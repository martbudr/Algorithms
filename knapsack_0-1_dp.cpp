#include <iostream>
#include <vector>

using namespace std;

/*
- jednej rzeczy moze byc tylko jedna sztuka
- szukana jest maksymalna wartosc plecaka (laczna wartosc rzeczy w nim zawartych)
- zapisywane sa rzeczy ktore wsadzane sa do plecaka aby osiagnac maksymalna wartosc
- zakladane jest, ze wszystkie dane sa prawidlowe (tj. m.in. ze nie ma takiej rzeczy, ktorej waga bylaby
    wieksza od maksymalnej wagi plecaka)
*/

int max_wartosc(int waga_plecaka, vector<int>& wartosci, vector<int>& wagi, int n) {
    vector<vector<int>> memo(n + 1), rzeczy(n + 1);
    vector<int> empty(waga_plecaka + 1, 0);
    memo[0] = empty;
    rzeczy[0] = empty;

    for (int i = 0; i <= waga_plecaka; ++i) {
        memo[0][i] = rzeczy[0][i] = 0;
    }

    for (int i = 1; i <= n; ++i) {
        memo[i] = empty;
        rzeczy[i] = empty;
        memo[i][0] = rzeczy[i][0] = 0;
        
        for (int j = 1; j < wagi[i - 1]; ++j) {
            memo[i][j] = memo[i - 1][j];
        }
        for (int j = wagi[i-1]; j <= waga_plecaka; ++j) {
            if (memo[i - 1][j - wagi[i-1]] + wartosci[i-1] > memo[i - 1][j]) {
                memo[i][j] = memo[i - 1][j - wagi[i-1]] + wartosci[i-1];
                rzeczy[i][j] = 1;
            }
            else {
                memo[i][j] = memo[i - 1][j];
                rzeczy[i][j] = 0;
            }
        }
    }

    return memo[n][waga_plecaka];
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
