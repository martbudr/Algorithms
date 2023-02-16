#include <iostream>
#include <vector>

using namespace std;

/* 
- jednego przedmiotu moze byc wiecej niz 1 sztuka
- szukana jest maksymalna wartosc plecaka (laczna wartosc rzeczy w nim zawartych)
- zapisywane sa rzeczy ktore wsadzane sa do plecaka aby osiagnac maksymalna wartosc (lecz zostaja w funkcji max_wartosc)
- zakladane jest, ze wszystkie dane sa prawidlowe (tj. m.in. ze nie ma takiej rzeczy, ktorej waga bylaby
    wieksza od maksymalnej wagi plecaka)
*/

void wypisz_rzeczy(vector<int>& rzeczy, vector<int>& wagi) {
    int j = rzeczy.size() - 1;// koniec tablicy rzeczy
    while (j > 0) {
        cout << rzeczy[j] + 1 << " ";
        j -= wagi[rzeczy[j]];
    }
    cout << '\n';
}

int max_wartosc(int waga_plecaka, vector<int>& wartosci, vector<int>& wagi, int n) {// rzeczy o jakiej maksymalnej wartosci mozna zmiescic w plecaku
    vector<int> memo(waga_plecaka + 1, 0),
        rzeczy(waga_plecaka + 1, -1);

    for (int i = 0; i < n; ++i) {// iterujac przez wszystkie rzeczy
        for (int j = wagi[i]; j <= waga_plecaka; ++j) {// iterujac od pierwszego do ostatniego mozliwego miejsca aktualnej rzeczy
            // memo[j] to maksimum z obecnego memo[j] (bez i-tej rzeczy; poprzednia wartosc)
            // i nowej wartosci tablicy (z i-ta rzecza)
            if (memo[j - wagi[i]] + wartosci[i] > memo[j]) {// to przed znakiem wiekszosci to wartosc tablicy kiedy i-ta rzecz jest zawarta (na miejscu j)
                memo[j] = memo[j - wagi[i]] + wartosci[i];
                rzeczy[j] = i;
            }
        }
    }

    wypisz_rzeczy(rzeczy, wagi);

    return memo[waga_plecaka];
}

int main(void)
{
    int waga_plecaka, n;// waga_plecaka - max waga, ktora moze przyjac plecak n - ilosc rzeczy
    cin >> waga_plecaka >> n;

    vector<int> wartosci(n), wagi(n);// wagi i wartosci (ile sa warte) rzeczy
    for (int i = 0; i < n; ++i) {
        cin >> wartosci[i] >> wagi[i];
    }

    cout << max_wartosc(waga_plecaka, wartosci, wagi, n) << '\n';
}
