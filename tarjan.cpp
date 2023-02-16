#include <iostream>
#include <vector>
#include <set>

using namespace std;

void dfs(int numer, int n, int &id, vector<int>& stos, vector<bool>& czy_na_stosie,
         vector<int>& indeks, vector<int>& low, vector<vector<int>>& nastepcy,
         vector<vector<int>>& silnie_spoj_skladowe, const int NIEODW)
    // numer - numer aktualnego wierzcholka
{
    stos.push_back(numer);
    czy_na_stosie[numer] = true;
    indeks[numer] = low[numer] = id++;

    // faktyczny dfs i znajdywanie wartosci low przy okazji
    for(int i=0, x=nastepcy[numer].size(); i<x; ++i){
        int wierz_nast = nastepcy[numer][i]; // nastepny wierzcholek

        if(indeks[wierz_nast] == NIEODW)
            dfs(wierz_nast, n, id, stos, czy_na_stosie, indeks, low, nastepcy, silnie_spoj_skladowe, NIEODW);

        if(czy_na_stosie[wierz_nast])
            low[numer] = min(low[numer], low[wierz_nast]);
    }

    // usuwanie ze stosu wierzcholkow nalezacych do jednej silnie spojnej skladowej
    if(indeks[numer] == low[numer]){
        vector<int> nowa_skladowa;
        while(true){
            int wierz = stos.back(); // wierzcholek na koncu stosu
            czy_na_stosie[wierz] = false;
            stos.pop_back();
            nowa_skladowa.push_back(wierz);

            low[wierz] = indeks[numer]; // zbedne w wiekszosci przypadkow
            if(indeks[wierz] == low[numer])
                break;
        }
        silnie_spoj_skladowe.push_back(nowa_skladowa);
    }
}

void tarjan(int n, vector<vector<int>>& nastepcy, vector<vector<int>>& silnie_spoj_skladowe)
{
    const int NIEODW = -1; // nieodwiedzony

    vector<int> indeks(n, NIEODW), // numer wyznaczony przez dfs (wlasc - wlasciwy)
        low(n); // najmniejszy indeks wierzcholka, do ktorego da sie dojsc w danym cyklu
    vector<int> stos; // stos z elementami
    vector<bool> czy_na_stosie(n, false);

    int id = 0; // aktualny numer indeksujacy wierzcholki (wyznaczane przez dfs)
    for(int i=0; i<n; ++i){
        if(indeks[i] == NIEODW){
            dfs(i, n, id, stos, czy_na_stosie, indeks, low, nastepcy, silnie_spoj_skladowe, NIEODW);
        }
    }
}

int main() // wierzcholki numerowane od 0
{
    int n, m;
    cin >> n >> m;

    int a, b;
    vector<vector<int>> nastepcy(n);
    for(int i=0; i<m; ++i){
        cin >> a >> b;
        nastepcy[a].push_back(b);
    }

    vector<vector<int>> silnie_spoj_skladowe;
    tarjan(n, nastepcy, silnie_spoj_skladowe);

    for(int i=0, x=silnie_spoj_skladowe.size(); i<x; ++i){
        for(int j=0, y=silnie_spoj_skladowe[i].size(); j<y; ++j)
            cout << silnie_spoj_skladowe[i][j] << ' ';
        cout << '\n';
    }
}
