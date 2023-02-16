#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int>a;
    int n,i,x,y,t;
    cin>>n;

    for(i=0; i<=n; i++){
        cin>>t;
        a.push_back(t);
    }

    cin>>x;
    y=0;
    for(i=0; i<=n; i++) y=y*x+a[i];

    for(i=0; i<=n; i++){
        cout<<a[i]<<"*x^"<<n-i;
        if(i!=n) cout<<" + ";
        else cout<<" = ";
    }
    cout<<y<<endl;
    return 0;
}
