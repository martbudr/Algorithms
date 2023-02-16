#include <iostream>

using namespace std;

const int N_MAX = 1e3 + 1;
vector<int> sas[N_MAX], pre[N_MAX];
int deg[N_MAX];
vector<int> ord;

void topo_sort(int st) // st - start
{
    queue<int> Q;
    Q.push(st);
    while(!Q.empty()){
        int u = Q.front();
        ord.push_back(u);
        Q.pop();

        for(int v : sas[u]){
            deg[v]--;
            if(deg[v] == 0) Q.push(v);
        }
    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
