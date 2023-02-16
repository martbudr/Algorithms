#include <bits/stdc++.h>

using namespace std;

const int N_MAX = 1e5,
    MOD = 1e9 + 7;
int n, k;
vector<vector<int>> mac(N_MAX, vector<int>(N_MAX)),
    jedn(N_MAX, vector<int>(N_MAX)); // macierz jednostkowa

vector<vector<int>> mnoz(vector<vector<int>>& mac_1, vector<vector<int>>& mac_2)
{
    vector<vector<int>> mac_wyn(N_MAX, vector<int>(N_MAX));
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            for(int k=0; k<n; ++k)
                mac_wyn[i][j] = (mac_wyn[i][j] + mac_1[i][k] * 1LL * mac_2[k][j]) % MOD;
        }
    }
    return mac_wyn;
}

void szyb_pot_mac() // szybkie potegowanie macierzy (podnoszenie do potegi k)
{
    for(int i=0; i<n; ++i)
        jedn[i][i] = 1;

    while(k){
        if(k%2 == 1) jedn = mnoz(jedn, mac);

        mac = mnoz(mac, mac);
        k /= 2;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j)
            cin >> mac[i][j];
    }

    szyb_pot_mac();

    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j)
            cout << jedn[i][j] << ' ';
        cout << '\n';
    }
}
