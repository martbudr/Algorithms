#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct punkt{
    int x,y;
};

int det(punkt p,punkt q,punkt r)
{
    int x=(q.y - p.y)*(r.x - q.x) - (q.x - p.x)*(r.y - q.y);
    if (x==0) return 0;
    return(x>0)? 1: 2;
}

void Otoczka(punkt p[], int n)
{
    if(n<3) return;
    vector<punkt> A;

    int p0=0;
    for (int i=1; i<n; i++){
        if(p[i].y<p[p0].y) p0=i;
        else if(p[i].y==p[p0].y){
            if(p[i].x<p[p0].x) p0=i;
        }
    }

    int a=p0,b;
    do{
        A.push_back(p[a]);
        b=(a+1)%n;
        for(int i=0; i<n; i++){
           if(det(p[a],p[i],p[b])==2) b=i;
        }
        a=b;
    }while(a!=p0);

    for (int i=0; i<A.size(); i++)
        cout<<A[i].x<<" "<<A[i].y<<endl;
}

int main()
{
    ifstream P("punkty.txt");
    int n; P>>n;
    punkt p[n];
    for(int i=0; i<n; i++){
        P>>p[i].x>>p[i].y;
    }
    Otoczka(p,n);
    return 0;
}
