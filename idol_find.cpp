#include <bits/stdc++.h>

using namespace std;

const int N_MAX = 1e3 + 1;
int n, m;
bool mac[N_MAX][N_MAX]; // mac[a][b] - czy a zna b; numeracja od 0

int znajdz_idola()
{
    int kand = 0;
    for(int i=1; i<n; ++i){
        if(mac[kand][i] == true)
            kand = i;
    }

    for(int i=0; i<n; ++i){
        if(i != kand && (mac[kand][i] || !mac[i][kand]))
            return -2;
    }
    return kand;
}

int main(void)
{
    cin >> n >> m;
    int a, b;
    for(int i=0; i<n; ++i) mac[i][i] = 1;
    for(int i=0; i<m; ++i){
        cin >> a >> b; // numeracja od 1
        mac[a-1][b-1] = true; // numeracja od 0
    }

    cout << znajdz_idola()+1 << '\n';
}
