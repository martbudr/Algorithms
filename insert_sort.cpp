#include <bits/stdc++.h>

using namespace std;

void insert_sort(int n, vector<int>& ciag)
{
    for(int i = 1; i < n; ++i){
        int tmp = ciag[i], j = i-1;
        while(j >= 0 && ciag[j] > tmp){
            ciag[j+1] = ciag[j];
            --j;
        }
        ciag[j+1] = tmp;
    }
}

int main(void)
{
    int n;
    cin >> n;
    vector<int> ciag(n);
    for(auto& i : ciag)
        cin >> i;

    insert_sort(n, ciag);

    for(auto& i : ciag)
        cout << i << ' ';
    cout << '\n';
}
