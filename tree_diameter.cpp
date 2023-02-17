#include <iostream>
#include <vector>

using namespace std;

struct graf
{
	bool L;
	vector<int>P;
	int F;
}*T;

void DFS(int x,int m,int *y)
{
	m++;
	T[x].L=1;
	if(m>T[*y].F) *y=x;
	for(int i=0; i<T[x].P.size(); i++){
		if(!T[T[x].P[i]].L){
            T[T[x].P[i]].F=m;
            DFS(T[x].P[i],m,y);
		}
	}
}

void Wypisz(int z,int m)
{
    T[z].L=1;
    m--;
    for(int i=0; i<T[z].P.size(); i++){
        if((!T[T[z].P[i]].L)&&(T[T[z].P[i]].F==m)){
            cout<<T[z].P[i]<<' ';
            Wypisz(T[z].P[i],m);
        }
    }
}

int main()
{
	int n,E,a,b,y=0,z=0;
	cin>>n;
	E=n-1;
	T=new graf[n];
	for(int i=0; i<E; i++){
		cin>>a>>b;
		T[a].P.push_back(b);
		T[b].P.push_back(a);
	}
	T[0].F=0;
	DFS(0,0,&y);
	for(int i=0; i<n; i++){
        T[i].L=0;
        T[i].F=-1;
	}
	DFS(y,0,&z);
	for(int i=0; i<n; i++) T[i].L=0;
	cout<<z<<' ';
	Wypisz(z,T[z].F);
	cout<<y<<endl;
	delete[]T;
	return 0;
}
