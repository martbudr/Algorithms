#include <bits/stdc++.h>

using namespace std;

const int N_MAX = 2e5 + 1;
int n;
vector<int> sas[N_MAX];
int pod[N_MAX]; // ilosc wierzcholkow w poddrzewie rooted at u (wliczajac u)
int centr;

void cnt_pod(int u, int p = -1)
{
    pod[u] = 1;
    for(auto v : sas[u]) if(v != p){
        cnt_pod(v, u);
        pod[u] += pod[v];
    }
}

void cen_cnt(int u)
{
    bool fnd = true;
    for(auto v : sas[u]){
        if(pod[v] > n/2){
            // aktualizacja wartosci pod, bo zmieniamy korzen drzewa z u na v
            pod[u] -= pod[v];
            pod[v] += pod[u];
            fnd = false;
            cen_cnt(v);
        }
    }
    if(fnd) centr = u;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    int a, b;
    for(int i=0; i<n-1; ++i){
        cin >> a >> b;
        sas[a].push_back(b);
        sas[b].push_back(a);
    }

    cnt_pod(1);
    cen_cnt(1);

    cout << centr << '\n';
}
