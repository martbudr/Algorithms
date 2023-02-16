#include <bits/stdc++.h>

using namespace std;

void sito(vector<int>& V)
{
    for(int i=2; i <= n; i++) V[i] = 0; /// nieraz mozna wyrzucic
    for(int i=2; i <= n; i++){
        if(V[i] == 0){
            for(int k=i*i; k <= n; k += i)
                if(V[k] == 0)
                    V[k] = i;
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long n;
    cin >> n;
    vector<long long> V;

    for(int i=2; i<=n; i++)
        if(V[i] == 0)
            cout << i << ' ';
    cout << '\n';
}
