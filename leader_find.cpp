#include <bits/stdc++.h>

using namespace std;

const int N_MAX = 1e9;
int n;
vector<int> tab(N_MAX);

bool sprawdz(int kand)
{
    int ile = 0;
    for(int i=0; i<n; ++i)
        if(tab[i] == kand) ile++;

    return (ile > n/2);
}

int znajdz_lidera()
{
    int kand = 0, ile = 0; // kand - kandydat, ile - ile aktualnie wiecej niz wszystkich pozostalych razem wzietych
    for(int i=0; i<n; ++i){
        if(ile == 0){
            kand = tab[i];
            ile++;
        }
        else if(tab[i] == kand)
            ile++;
        else
            ile--;
    }

    return (sprawdz(kand) ? kand : -1);
}

int main(void)
{
    cin >> n;
    for(int i=0; i<n; ++i)
        cin >> tab[i];

    cout << znajdz_lidera() << '\n';
}
