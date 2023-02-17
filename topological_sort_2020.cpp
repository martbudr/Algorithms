//1.05.2020
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    const int X=10000;
    vector<int>g[X];
    int t[X],l[X],p=1,k=1;
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i=0; i<=n; i++) t[i]=0;
    for (int i=0; i<m; i++){
         int v,w;
         scanf("%d %d",&v,&w);
         t[w]++;
         g[v].push_back(w);
    }
    for (int i=0; i<n; i++) if(t[i]==0) l[k++]=i;
    for (int i=1; i<=n; i++){
         int a=l[p];
         p++;
         while(!g[a].empty()){
                 t[g[a].back()]--;
                 if (t[g[a].back()]==0) l[k++]=g[a].back();
                 g[a].pop_back();
         }
    }
    for (int i=1; i<=n; i++) printf("%d ",l[i]);
    return 0;
}
