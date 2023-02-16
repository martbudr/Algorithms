#include <bits/stdc++.h>

using namespace std;

const int N_MAX = 1e6 + 1;
int n, q;
long long tree[N_MAX];

int lsb(int x) // least significant bit (a way to get the length of the smallest interval containing x)
{
    return (x & -x);
}

void ins(int x, int amt) // insert
{
    while(x <= n){
        tree[x] += amt;
        x += lsb(x);
    }
}

int query(int a)
{
    if(a == 0) return 0;

    long long sum = 0;
    while(a > 0){
        sum += tree[a];
        a -= lsb(a);
    }
    return sum;
}

int sum(int a, int b) // find sum
{
    return query(b) - query(a-1);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    int amt;
    for(int i=1; i<=n; ++i){
        cin >> amt;
        ins(i, amt);
    }

    int que;
    while(q--){
        cin >> que;
        if(que == 1){
            int x;
            cin >> x >> amt;
            ins(x, amt);
        }
        else if(que == 2){
            int a, b;
            cin >> a >> b;
            cout << sum(a, b) << '\n';
        }
    }
}
