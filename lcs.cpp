#include <bits/stdc++.h>

using namespace std;

const int NM_MAX = 2e3 + 1;
string A, B;
int n, m;
int dp[2][NM_MAX];

int nwp()
{
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            if(A[i-1] == B[j-1])
                dp[i%2][j] = dp[(i-1)%2][j-1] + 1;
            else dp[i%2][j] = max(dp[i%2][j-1], dp[(i-1)%2][j]);
        }
    }
    return dp[n%2][m];
}

int main(void)
{
    cin >> A >> B;
    n = A.size(); m = B.size();

    cout << nwp() << '\n';
}
