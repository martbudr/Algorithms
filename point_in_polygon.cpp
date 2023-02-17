//8.06.2020
#include <iostream>

using namespace std;

struct wierz{
    int x,y;
};

bool CzyWspolniniowe(wierz p,wierz q,wierz r)
{
    if((q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x)) && (q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)))
        return 1;
    return 0;
}

int det(wierz p,wierz q,wierz r)
{
    int x = (q.y - p.y)*(r.x - q.x) - (q.x - p.x)*(r.y - q.y);
    if(!x) return 0;
    return(x>0)? 1: -1;
}

bool CzyPrzecinaja(wierz p1,wierz q1,wierz p2,wierz q2)
{
    int x1 = det(p1,q1,p2),
        x2 = det(p1,q1,q2),
        x3 = det(p2,q2,p1),
        x4 = det(p2,q2,q1);
    if(x1!=x2 && x3!=x4) return 1;
    if(!x1 && CzyWspolniniowe(p1,p2,q1)) return 1;
    if(!x2 && CzyWspolniniowe(p1,q2,q1)) return 1;
    if(!x3 && CzyWspolniniowe(p2,p1,q2)) return 1;
    if(!x4 && CzyWspolniniowe(p2,q1,q2)) return 1;
    return 0;
}

bool CzyWSrodku(wierz N[],int n,wierz p)
{
    if (n<3) return 0;
    wierz extreme={INT_MAX,p.y};

    int l=0,i=0;
    do{
        int next=(i+1)%n;
        if(CzyPrzecinaja(N[i],N[next],p,extreme)){
            if(det(N[i],p,N[next])==0) return CzyWspolniniowe(N[i],p,N[next]);
            l++;
        }
        i=next;
    }while(i);
    return l%2==1;
}

int main()
{
    int n,k;
    cin>>n;
    wierz N[n];
    for(int i=0; i<n; i++){
        cin>>N[i].x>>N[i].y;
    }
    cin>>k;
    wierz K[k];
    for(int i=0; i<k; i++){
        cin>>K[i].x>>K[i].y;
        CzyWSrodku(N,n,K[i])?cout<<'t'<<endl:cout<<'n'<<endl;
    }
    return 0;
}
