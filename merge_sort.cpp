#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int *T;
void Scal(int t[],int l,int s,int p)
{
    int i=l,j=s+1;
    for (int i=l; i<=p; i++) T[i]=t[i];
    for (int k=l; k<=p; k++){
        if (i<=s){
            if (j<=p)
            {
                if (T[j]<T[i]) t[k]=T[j++];
                else t[k]=T[i++];
            }
            else t[k]=T[i++];
        }
        else t[k]=T[j++];
    }
}

void SortPrzezScalanie(int t[],int l,int p)
{
    if (p<=l) return;
    int s=(p+l)/2;
    SortPrzezScalanie(t,l,s);
    SortPrzezScalanie(t,s+1,p);
    Scal(t,l,s,p);
}

int main()
{
    int n,a,b;
    cout<<"Podaj liczbe elementow: ";
    cin>>n;
    cout<<"Podaj przedzial: ";
    cin>>a>>b;
    if (a>b) return -1;
    srand(time(NULL));
    int t[n];
    T=new int[n];
    cout<<"Nieposortowana tablica: "<<endl;
    for (int i=0; i<n; i++){
        t[i]=rand()%(b-a+1)+a;
        cout<<t[i]<<' ';
    }
    cout<<endl;
    int l=0,p=n-1;
    SortPrzezScalanie(t,l,p);
    cout<<"Posortowana tablica: "<<endl;
    for (int i=0; i<n; i++) cout<<t[i]<<' ';
    cout<<endl;
    return 0;
}
