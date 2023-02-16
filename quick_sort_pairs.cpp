#include <iostream>

using namespace std;

void sortuj(int lewy, int prawy, vector<pair<int,int>>& liczby)
{
    if (lewy == prawy) return;

    int i = lewy, j = prawy;//i, j - "iteratory"
    int pivot = liczby[(lewy + prawy) / 2].first;
    do {//do while po to, aby o raz mniej sprawdzac warunek (na poczatku jest niepotrzebny)
        while (liczby[i].first < pivot) ++i;
        while (pivot < liczby[j].first) --j;

        if (i <= j) {//przypadek skrajny - pivot - tez swapowac, aby po tym zwiekszyc i i zmniejszyc j, i zakonczyc
            swap(liczby[i], liczby[j]);
            ++i; --j;//potrzebne, bo inaczej nie zawsze przerywa
        }
        else break;
    }while (i <= j);

    if(lewy < j)//instrukcja warunkowa sprawdzana dlatego, bo w niektorych przypadkach pivot jest jedna z 2 najmniejszych wartosci
        sortuj(lewy, j, liczby);
    if(i < prawy)//to samo tylko ze jedna z 2 najwiekszych
        sortuj(i, prawy, liczby);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    sortuj();
}
