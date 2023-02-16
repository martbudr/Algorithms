#include <bits/stdc++.h>

using namespace std;

const int N_MAX = 1e6 + 1;
int n; // ilosc elementow
int A[N_MAX];

class IntervalTree {
    int rozm, LISC = 1; // rozmiar, miejsce pierwszego liscia
    vector<int> drzewo;

    void szuk_rozm() {
        while(n > LISC) LISC <<= 1;
        rozm = LISC<<1;

        drzewo.reserve(rozm+1);
    }

public:
    void wstaw(int wart, int miej) {
        miej += LISC;
        while(miej){
            drzewo[miej] += wart;
            miej /= 2;
        }
    }

    int suma(int l, int p) {
        l += LISC;
        p += LISC;

        int ans = drzewo[l];
        if(l != p) ans += drzewo[p];

        while(l/2 != p/2){
            if(l%2 == 0) ans += drzewo[l+1];
            if(p%2 == 1) ans += drzewo[p-1];
            l /= 2;
            p /= 2;
        }
        return ans;
    }
};

IntervalTree drzewo;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> A[i];
        drzewo.wstaw(A[i], i);
    }

    int t; // ilosc zapytan (wstawianie lub suma)
    cin >> t;
    while(t--){
        char c;
        cin >> c;
        if(c == 'W'){ // wstawianie
            int wart, miej;
            cin >> wart >> miej;
            drzewo.wstaw(wart, miej);
        }
        else{ // suma na przedziale
            int l, p;
            cin >> l >> p;
            cout << drzewo.suma(l, p) << '\n';
        }
    }
}
