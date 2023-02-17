//24.05.2020
#include <iostream>

using namespace std;

struct wierz{
    int w;
    struct wierz *ojciec;
    struct wierz *l_syn;
    struct wierz *p_syn;
};

struct wierz *korzen;

struct wierz *szukaj(struct wierz *start, int k)
{
    if (start->w == k) return start;
    else if ((k < start->w) && (start->l_syn != NULL)) return szukaj(start->l_syn, k);
    else if (k > start->w && start->p_syn != NULL) return szukaj(start->p_syn, k);
    return NULL;
}

struct wierz *naj_lewo(struct wierz *start)
{
    if(start->l_syn != NULL)
        return naj_lewo(start->l_syn);
    else return start;
}

void Wypisz(struct wierz *start)
{
    if(start->l_syn != NULL)
        Wypisz(start->l_syn);

    cout<<start->w<<' ';

    if(start->p_syn != NULL)
        Wypisz(start->p_syn);
}

void Dodaj(int k,struct wierz *start)
{
    if (korzen==NULL){
        korzen = new wierz[sizeof *korzen];
        korzen->w = k;
        korzen->l_syn = NULL;
        korzen->p_syn = NULL;
        korzen->ojciec = NULL;
    }
    else if(k < start->w){
        if(start->l_syn != NULL){
            Dodaj(k,start->l_syn);
        }
        else{
            wierz *nowy = new wierz;
            nowy->w = k;
            nowy->l_syn = NULL;
            nowy->p_syn = NULL;
            nowy->ojciec = start;
            start->l_syn=nowy;
        }
    }
    else{
        if(start->p_syn!=NULL){
            Dodaj(k,start->p_syn);
        }
        else{
            wierz *nowy = new wierz;
            nowy->w = k;
            nowy->l_syn = NULL;
            nowy->p_syn = NULL;
            nowy->ojciec = start;
            start->p_syn = nowy;
        }
    }
}

void Usun(struct wierz *start)
{
    if(start->l_syn == NULL && start->p_syn == NULL){
        if(start->ojciec == NULL){
            korzen=NULL;
        }
        else if(start->ojciec->l_syn == start){
            start->ojciec->l_syn = NULL;
        }
        else{
            start->ojciec->p_syn = NULL;
        }
        delete start;
    }
    else if(start->l_syn == NULL || start->p_syn == NULL){
        if(start->l_syn == NULL){
            if(start->ojciec == NULL){
                korzen = start->p_syn;
            }
            else if(start->ojciec->l_syn == start){
                start->ojciec->l_syn = start->p_syn;
            }
            else{
                start->ojciec->p_syn = start->p_syn;
            }
        }
        else{
            if(start->ojciec == NULL){
                korzen = start->l_syn;
            }
            else if(start->ojciec->l_syn == start){
                start->ojciec->l_syn = start->l_syn;
            }
            else{
                start->ojciec->p_syn = start->l_syn;
            }
        }
        delete start;
    }
    else {
        struct wierz *temp;
        temp = naj_lewo(start->p_syn);
        start->w = temp->w;
        Usun(temp);
    }
}

void Suma(struct wierz *start,int &s)
{
    if(start->l_syn != NULL)
        Suma(start->l_syn, s);

    s += start->w;

    if(start->p_syn != NULL)
        Suma(start->p_syn, s);
}

int main()
{
    int x,s=0;
    korzen=NULL;

    do{
        cout<<"\t\tMenu"<<endl;
        cout<<"1. Wypisz elementy drzewa w porzadku inorder"<<endl;
        cout<<"2. Dodaj element do drzewa"<<endl;
        cout<<"3. Usun element drzewa"<<endl;
        cout<<"4. Oblicz i wypisz sume wartosci elementow w lisciach drzewa"<<endl;
        cout<<"5. Koniec"<<endl;
        cout<<"Podaj liczbe od 1 do 5: ";
        cin>>x;
        int k=0;
        switch(x)
        {
        case 1:
            cout<<"Elementy drzewa w porzadku inorder: "<<endl;
            if(korzen!=NULL) Wypisz(korzen);
            cout<<endl;
            break;
        case 2:
            cout<<"Podaj element do dodania: ";
            cin>>k;
            Dodaj(k,korzen);
            break;
        case 3:
            if (korzen==NULL){
                cout<<"Nie ma czego usunac"<<endl;
                break;
            }
            cout<<"Podaj element do usuniecia: ";
            cin>>k;
            Usun(szukaj(korzen,k));
            break;
        case 4:
            if(korzen!=NULL) Suma(korzen,s);
            cout<<"Suma wartosci wynosi: "<<s<<endl;
            break;
        case 5:
            cout<<"Koniec"<<endl;
            break;
        default:
            cout<<"Niepoprawna liczba."<<endl;
            break;
        }
    }while(x!=5);

    return 0;
}
