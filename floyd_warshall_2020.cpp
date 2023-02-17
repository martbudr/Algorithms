//alg Floyda-Warshalla
#include <iostream>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int W[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) W[i][j]=INT_MAX/2;
        W[i][i]=0;
    }
    cout<<endl<<"   ";
    for(int i=0; i<n; i++) cout<<i<<"\t";
    cout<<endl;
    for(int i=0; i<n; i++){
        cout<<i<<"  ";
        for(int j=0; j<n; j++) cout<<W[i][j]<<'\t';
        cout<<endl;
    }
    cout<<endl;

    for(int i=0; i<m; i++){
        int a,b,w;
        cin>>a>>b>>w;
        W[a][b]=w;
    }
    cout<<endl<<"   ";
    for(int i=0; i<n; i++) cout<<i<<"\t";
    cout<<endl;
    for(int i=0; i<n; i++){
        cout<<i<<"  ";
        for(int j=0; j<n; j++) cout<<W[i][j]<<'\t';
        cout<<endl;
    }

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            if(W[i][k]!=INT_MAX/2){
                for(int j=0; j<n; j++){
                    if(W[i][j] > W[i][k]+W[k][j])
                        W[i][j] = W[i][k]+W[k][j];
                    cout<<endl<<"   ";
                    for(int i=0; i<n; i++) cout<<i<<"\t";
                    cout<<endl;
                    for(int i=0; i<n; i++){
                        cout<<i<<"  ";
                        for(int j=0; j<n; j++) cout<<W[i][j]<<'\t';
                        cout<<endl;
                    }
                }
            }
        }
    }
    return 0;
}
