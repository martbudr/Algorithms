#include <bits/stdc++.h>

using namespace std;

struct Node{
    int wart;
    Node *lewy = NULL,
        *prawy = NULL;
};

Node* korz = NULL; // korzen

void dodaj(int wart) /// problemy z lewymi i prawymi wskaznikami
{
    Node* wierz = korz;
    if(wierz == NULL){
        wierz = new Node;
        wierz->wart = wart;
        cout << wierz->wart << ' ';
        korz = wierz;
        return;
    }

    while(wierz != NULL){
        if(wart <= wierz->wart)
            wierz = wierz->lewy;
        else wierz = wierz->prawy;
    }

}

void usun(int wart)
{
    Node* wierz = korz;

}

void preorder(Node* akt = korz)
{
    if(akt == NULL)
        return;

    cout << akt->wart << ' ';
    preorder(akt->lewy);
    preorder(akt->prawy);
}

void inorder(Node* akt = korz)
{
    if(akt == NULL)
        return;

    preorder(akt->lewy);
    cout << akt->wart << ' ';
    preorder(akt->prawy);
}

void postorder(Node* akt = korz)
{
    if(akt == NULL)
        return;

    preorder(akt->lewy);
    preorder(akt->prawy);
    cout << akt->wart << ' ';
}

int main(void)
{
    int wczyt = 1,
        wart;
    while(wczyt){
        cin >> wczyt;
        switch(wczyt){
            case 1:
                cin >> wart;
                dodaj(wart);
                break;
            case 2:
                cin >> wart;
                usun(wart);
                break;
            case 3:
                preorder();
                cout << '\n';
                break;
            case 4:
                inorder();
                cout << '\n';
                break;
            case 5:
                postorder();
                cout << '\n';
                break;
        }
    }
}
