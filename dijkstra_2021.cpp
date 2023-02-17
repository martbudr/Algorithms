//27.02.2021
#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

struct wierz {
    bool odwiedzony;
    vector<int> sasiedzi,// do ktorych wierzcholkow prowadza krawedzie
        wagi_kraw;// wagi poszczegolnych krawedzi prowadzacych do sasiadow
};

int dijkstra(int wierz_pocz, int wierz_kon, wierz* Wierz, int v) {// to nie do konca dijkstra
    vector<int> min_dl(v, INT_MAX);// minimalna dlugosc do danego wierzcholka
    queue<int> Q;// wierzcholki do rozpatrzenia

    Q.push(wierz_pocz);
    Wierz[wierz_pocz].odwiedzony = true;
    min_dl[wierz_pocz] = 0;

    while (!Q.empty()) {
        int aktualny = Q.front();
        Q.pop();
        for (int i = 0, n = Wierz[aktualny].sasiedzi.size(); i < n; ++i) {
            min_dl[Wierz[aktualny].sasiedzi[i]] =
                min(min_dl[Wierz[aktualny].sasiedzi[i]], min_dl[aktualny] + Wierz[aktualny].wagi_kraw[i]);// minimum z obecnej dlugosci do nastepnego
            //i dlugosci do obecnego wierzcholka + krawedzi z niego do nastepnego

            if (Wierz[Wierz[aktualny].sasiedzi[i]].odwiedzony == false) {// jesli sasiad nie odwiedzony
                Q.push(Wierz[aktualny].sasiedzi[i]);
                Wierz[Wierz[aktualny].sasiedzi[i]].odwiedzony = true;
            }
        }
    }

    return min_dl[wierz_kon];
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int v, k;// wierzcholki, krawedzie
        cin >> v >> k;

        wierz* Wierz = new wierz[v];
        for (int i = 0; i < v; ++i)
            Wierz[i].odwiedzony = false;

        int a, b, c;// zmienne pomocnicze do wczytywania
        for (int i = 0; i < k; ++i) {
            cin >> a >> b >> c;
            Wierz[a - 1].sasiedzi.push_back(b - 1);
            Wierz[a - 1].wagi_kraw.push_back(c);
        }

        cin >> a >> b;// droga z ktorego do ktorego szukana

        int wynik = dijkstra(a - 1, b - 1, Wierz, v);
        if (wynik == INT_MAX) cout << "NIE" << '\n';
        else cout << wynik << '\n';

        delete[] Wierz;
    }
}
