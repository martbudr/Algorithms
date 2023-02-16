// algorytm znajdujacy optymalne rozmieszczenie nawiasow w celu mnozenia wielu macierzy
#include <bits/stdc++.h>

using namespace std;

const int N_MAX = 1e3 + 1;
int n;
int p[N_MAX], q[N_MAX]; // 1szy i 2gi wymiar - wielkosci
long long dp[N_MAX][N_MAX]; // najmniejsza ilosc mnozen dla przedzialu i...j
int dp_dla[N_MAX][N_MAX]; // dla podzialu w ktorym miejsu ilosc mnozen jest najmniejsza

int main(void)
{
    cin >> n;
    for(int i=1; i<=n; ++i)
        cin >> p[i] >> q[i];

    for(int len=2; len<=n; ++len){
        for(int i=1; i<=n-len+1; ++i){
            int j = i+len-1;

            dp[i][j] = LLONG_MAX;
            for(int k=i; k<j; ++k){
                long long ne = dp[i][k] + dp[k+1][j] + p[i]*q[k]*q[j];
                if(ne < dp[i][j]){
                    dp[i][j] = ne;
                    dp_dla[i][j] = k;
                }
            }
        }
    }
    cout << dp[1][n] << '\n'; // optymalna ilosc mnozen dla calosci

    // + rekurencyjne odtwarzanie podzialu
}
