// nie dziala
#include <bits/stdc++.h>

using namespace std;

const int N_MAX = 1e6 + 1, p = 21, LISC = (1<<(p-1));
int n, q;
int tree[1<<p], lazy[1<<p];

void update(int s, int amt)
{
    tree[s] += amt;
    if(s < LISC) lazy[s] += amt;
}

void push(int s) // przesuwanie wartosci lazy do synow
{
    for(int i=p-1; i>0; --i){
        int curr = s>>i;
        if(lazy[curr] == 0) continue;

        update(curr<<1, lazy[curr]);
        update((curr<<1) + 1, lazy[curr]);
        lazy[curr] = 0;
    }
    tree[s] += lazy[s];
    lazy[s] = 0;
}

void build(int s) // niepotrzebne dla sumy, ale jest dla formalnosci (bo jesli brac max na przyklad, to jest juz potrzebne)
{
    s >>= 1;
    while(s){
        tree[s] = tree[s<<1] + tree[(s<<1) + 1];
        s >>= 1;
    }
}

void ins(int l, int r, int amt) // insert
{
    int _l = l += LISC-1, _r = r += LISC-1;

    push(l); push(r);

    update(l, amt);
    if(l != r) update(r, amt);
    while(l>>1 != r>>1){
        if(l%2 == 0) update(l+1, amt);
        if(r%2 == 1) update(r-1, amt);

        l >>= 1; r >>= 1;
    }

    build(_l); build(_r);
}

int query(int l, int r)
{
    l += LISC-1; r += LISC-1;

    push(l); push(r);

    int ans = tree[l];
    if(l != r) ans += tree[r];
    while(l>>1 != r>>1){
        if(l%2 == 0) ans += tree[l+1];
        if(r%2 == 1) ans += tree[r-1];

        l >>= 1; r >>= 1;
    }
    return ans;
}

int main(void)
{
    cin >> n;
    int a;
    for(int i=1; i<=n; ++i){
        cin >> a;
        ins(i, i, a);
    }

    cin >> q;
    int op, l, r; // 1 - insert, 2 - query
    while(q--){
        cin >> op >> l >> r;
        if(op == 1){
            int amt;
            cin >> amt;
            ins(l, r, amt);
        }
        else{
           for(int i=1; i<=n; ++i) cout << tree[i+LISC-1] << ' ';
        cout << '\n';
           cout << query(l, r) << '\n';
        }
    }
}
