#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct wezel{
    char c;
    int ile;
    wezel *next;
    wezel *l;
    wezel *p;
};

void Wezly(wezel *&root,string s)
{
    int x;
    char c;
    wezel *p;
    bool t;

    for(int i=0; i<s.size(); i++){
        p=root;
        while(p && p->c != s[i]) p= p->next;
        if(!p){
            p=new wezel;
            p->next = root;
            p->l = NULL;
            p->p = NULL;
            p->c = s[i];
            p->ile = 0;
            root=p;
        }
        p->ile++;
    }
    do{
        t=true;
        p=root;
        while(p->next){
            if(p->ile > p->next->ile){
                c = p->c;
                p->c = p->next->c;
                p->next->c = c;
                x = p->ile;
                p->ile = p->next->ile;
                p->next->ile = x;
                t=false;
            }
            p = p->next;
        }
    }while(!t);
}

void Drzewo(wezel *&root)
{
    wezel *w1,*w2,*p,*r;
    while(1){
        w1=root;
        w2= w1->next;
        if(!w2) break;
        root = w2->next;
        p=new wezel;
        p->l = w1;
        p->p = w2;
        p->ile = w1->ile + w2->ile;

        if(!root || (p->ile <= root->ile)){
            p->next = root;
            root=p;
            continue;
        }

        r=root;
        while(r->next && (p->ile > r->next->ile)) r = r->next;

        p->next = r->next;
        r->next = p;
    }
}

bool Wypisz(wezel *p, string x)
{
    if(!p->l)
        cout<<p->c<<": "<<x<<endl;
    else return Wypisz(p->l,x+"0") || Wypisz(p->p,x+"1");
    return 0;
}

void Rozszyfruj(wezel *&root,string r)
{
    int i=-1,s=r.size()-1;
    wezel *p;
    while(i<s){
        p=root;
        while(p->l){
            i++;
            if(r[i]=='0') p= p->l;
            else if(r[i]=='1') p= p->p;
        }
        cout<<p->c;
    }
}

int main()
{
    wezel *root;
    root=NULL;
    string s;
    ifstream T("tekst.txt");
    if(!T){
        cout<<"Nie znaleziono pliku wejsciowego"<<endl;
        return 0;
    }
    while(!T.eof()){
        getline(T,s);
        Wezly(root,s);
    }
    Drzewo(root);
    Wypisz(root,"");

    cout<<endl;
    string r;
    cin>>r;
    Rozszyfruj(root,r);

    T.close();
    return 0;
}
