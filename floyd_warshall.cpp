#include <bits/stdc++.h>

using namespace std;

int N_MAX = 1e3 + 1;
int n, m;
vector<vector<int>> M(N_MAX, vector<int>(N_MAX, 1e6)); // macierz
vector<vector<int>> nast(N_MAX, vector<int>(N_MAX, 1e6)); // nastepny wierzcholek

void floyd_warshall()
{
    for(int k=0; k<n; ++k){
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(M[i][k] + M[k][j] < M[i][j]){
                    nast[i][j] = nast[i][k];
                    M[i][j] = M[i][k] + M[k][j];
                }
            }
        }
    }
}

void droga(int a, int b)
{
    cout << a << ' ';
    while(a != b){
        a = nast[a][b];
        cout << a << ' ';
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    int a, b, w;
    for(int i=0; i<m; ++i){
        cin >> a >> b >> w;
        M[a][b] = M[b][a] = w;
        nast[a][b] = b;
    }

    floyd_warshall();
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j)
            cout << M[i][j] << ' ';
        cout << '\n';
    }
    cin >> a >> b;
    droga(a, b);
}
