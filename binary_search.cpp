#include <bits/stdc++.h>

using namespace std;

int wysz_bin(int szuk, vector<int>& V) // szukanie najwiekszego mniejszego rownego szukanemu
{
    int l = 0, r = V.size()-1;
    while(l < r){
        int mid = (l+r+1) / 2;
        if(V[mid] <= szuk)
            l = mid;
        else r = mid-1;
    }
    return l;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> V(n);
    for(auto &i : V)
        cin >> i;

    int x; // od tego el ma byc mniejszy rowny
    cin >> x;

    cout << wysz_bin(x, V) << '\n';
}
