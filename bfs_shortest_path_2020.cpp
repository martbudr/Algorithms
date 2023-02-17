//6.05.2020
#include<iostream>
#include<queue>

using namespace std;

struct graf
{
    bool Q;
    vector<int>P;
}*L;

void BFS(int x,int F[])
{
    queue<int>Q;
    Q.push(x);
    L[x].Q=1;
    while(!Q.empty()){
        x=Q.front();
        Q.pop();
        for(int i=0; i<L[x].P.size(); i++){
            if(!L[L[x].P[i]].Q){
                Q.push(L[x].P[i]);
                F[L[x].P[i]]=x;
                L[L[x].P[i]].Q=1;
            }
        }
    }
}

int main()
{
    int n,m,a,b;
    cin>>n;
    int F[n];
    for (int i=0; i<n; i++) F[i]=-1;
    L=new graf[n];
    cin>>m;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        L[a].P.push_back(b);
        L[b].P.push_back(a);
    }
    BFS(0,F);
    delete[]L;

    int v,u;
    cin>>v>>u;
    vector<int>A;
    A.push_back(u);
    if (v==u){
        cout<<v<<endl;
        return 0;
    }
    do{
        u=F[u];
        A.push_back(u);
    }while(u!=v);
    int s=A.size();
    for (int i=0; i<s; i++){
        cout<<A.back()<<' ';
        A.pop_back();
    }
    return 0;
}
