//Algorytm Prima-Dijkstry
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,m,a,b,w,wiersz=0,wierz=0,s;
    cin>>n>>m;
    vector<vector<int> >G;
    vector<int>F,dist,near,g;

    for(int i=0; i<n; i++) g.push_back(0);
    for(int i=0; i<n; i++){
        F.push_back(0);
        dist.push_back(n*n);
        near.push_back(n*n);
        G.push_back(g);
    }

    for (int i=0; i<m; i++){
        cin>>a>>b>>w;
        G[a][b]=G[b][a]=w;
    }

    dist[wierz]=0;
    F[wierz]=1;

    while(wierz!=n){
        for(int i=0; i<n; i++){
            if(G[wiersz][i] && !F[i]){
                if(dist[i]>G[wiersz][i]){
                    dist[i]=G[wiersz][i];
                    near[i]=wiersz;
                }
            }
        }

        s=n*n;
        for(int i=0; i<n; i++){
            if(!F[i]){
                if(dist[i]<s){
                    s=dist[i];
                    wiersz=i;
                }
            }
        }

        F[wiersz]=1;
        wierz++;
    }

    s=0;
    cout<<endl;
    for(int i=0; i<n; i++){
        if(near[i]<n*n) cout<<near[i]<<' '<<i<<endl;
        s+=dist[i];
    }
    cout<<s<<endl;
    return 0;
}
