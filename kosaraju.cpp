#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs_1(int current, vector<bool>& czy_odw, vector<vector<int>>& nastepcy, stack<int>& kolejnosc) // rekurencyjny
{
    czy_odw[current] = true;

    for(int i=0, x=nastepcy[current].size(); i<x; ++i){
        int nast_wierz = nastepcy[current][i];
        if(!czy_odw[nast_wierz]){
            dfs_1(nast_wierz, czy_odw, nastepcy, kolejnosc);
        }
    }

    kolejnosc.push(current);
}

vector<vector<int>> transponuj(vector<vector<int>>& nastepcy)
{
    int n = nastepcy.size();

    vector<vector<int>> nowi_nastepcy(n);
    for(int i=0; i<n; ++i){
        for(int j=0, x=nastepcy[i].size(); j<x; ++j)
            nowi_nastepcy[nastepcy[i][j]].push_back(i);
    }
    return nowi_nastepcy;
}

const int NIEODW = -1;

void dfs_2(stack<int>& kolejnosc, int akt_skladowa, vector<int>& w_ktorej_skladowej, vector<int>& ile_w_skladowej, vector<vector<int>>& nowi_nastepcy)
    // iteracyjny, dla wszystkich wierzcholkow ze wszystkich skladowych (nie chodzi o silnie spojne)
{
    stack<int> stos;
    stos.push(kolejnosc.top());
    kolejnosc.pop();

    while(!stos.empty()){
        int current = stos.top();
        stos.pop();
        w_ktorej_skladowej[current] = akt_skladowa;
        ile_w_skladowej[akt_skladowa]++;

        for(int i=0, x=nowi_nastepcy[current].size(); i<x; ++i){
            int nast_wierz = nowi_nastepcy[current][i];
            if(w_ktorej_skladowej[nast_wierz] == NIEODW)
                stos.push(nast_wierz);
        }
    }
}

void alg_kosaraju(int n, vector<int>& w_ktorej_skladowej, vector<int>& ile_w_skladowej, vector<vector<int>>& nastepcy)
    // znajdowanie wszystkich silnie spojnych skladowych w grafie (dfs -> transpozycja -> dfs)
{
    vector<bool> czy_odw(n, false);
    stack<int> kolejnosc; // kolejnosc przetwarzania wierzcholkow w 2 dfsie
    for(int i=0; i<n; ++i){
        if(!czy_odw[i])
            dfs_1(i, czy_odw, nastepcy, kolejnosc);
    }

    vector<vector<int>> nowi_nastepcy = transponuj(nastepcy);

    int akt_skladowa = 0; // numer aktualnej skladowej
    while(!kolejnosc.empty()){
        if(w_ktorej_skladowej[kolejnosc.top()] != NIEODW){ // jesli odwiedzony to go usun
            kolejnosc.pop();
            continue;
        }

        ile_w_skladowej.push_back(0);

        dfs_2(kolejnosc, akt_skladowa, w_ktorej_skladowej, ile_w_skladowej, nowi_nastepcy);

        akt_skladowa++;
    }
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m; // numeracja od 1
    cin >> n >> m;
    vector<vector<int>> nastepcy(n);

    int a, b;
    for(int i=0; i<m; ++i){
        cin >> a >> b;
        nastepcy[a-1].push_back(b-1);
    }

    vector<int> w_ktorej_skladowej(n, NIEODW), // NIEODW - wierzcholek nieodwiedzony
        ile_w_skladowej;
    alg_kosaraju(n, w_ktorej_skladowej, ile_w_skladowej, nastepcy);
}
