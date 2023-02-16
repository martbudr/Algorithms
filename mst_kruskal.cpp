#include <bits/stdc++.h>

using namespace std;

const int N_MAX = 1e6 + 1;
int n, m;
vector<pair<pair<int,int>, int>> kraw(N_MAX); // (a,b), waga
typedef pair<int,int> P;
priority_queue<P, vector<P>, greater<P>> Q; // waga, nr krawedzi

int DSU[N_MAX]; // podzbior
int znajdz(int id) // podzbior wierzcholka
{
    if(DSU[id] == id) return id;
    DSU[id] = znajdz(DSU[id]);
    return DSU[id];
}

void polacz(int id1, int id2) // laczenie dwoch podzbiorow
{
    if(znajdz(id1) != znajdz(id2))
        DSU[DSU[id1]] = DSU[id2];
}

int mst[N_MAX]; // numery krawedzi wchodzacych w sklad mst
int suma = 0; // suma wag krawedzi skladajacych sie na mst
void kruskal()
{
    for(int i=1; i<=n; ++i)
        DSU[i] = i;

    int t = 0;
    while(t < n-1){
        pair<int,int> akt = Q.top();  // aktualnie rozwazana krawedz
        Q.pop();
        int a = kraw[akt.second].first.first, b = kraw[akt.second].first.second;
        if(znajdz(a) != znajdz(b)){
            polacz(a, b);
            mst[t] = akt.second;
            suma += kraw[akt.second].second;
            t++;
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<m; ++i){
        cin >> kraw[i].first.first >> kraw[i].first.second >> kraw[i].second;
        Q.push(make_pair(kraw[i].second, i));
    }

    kruskal();
    cout << suma << '\n';
    for(int i=0; i<n-1; ++i)
        cout << mst[i] << ' ';
    cout << '\n';
}
