#include <iostream>

using namespace std;

void quickSort(int left,int right, int *array) {//left, right - zakresy tablicy
    if (left == right) return;

    int i = left, j = right;//i, j - "iteratory"
    int pivot = array[(left + right) / 2];
    do {//do while po to, aby o raz mniej sprawdzac warunek (na poczatku jest niepotrzebny)
        while (array[i] < pivot) ++i;
        while (pivot < array[j]) --j;

        if (i <= j) {//przypadek skrajny - pivot - tez swapowac, aby po tym zwiekszyc i i zmniejszyc j, i zakonczyc
            swap(array[i], array[j]);
            ++i; --j;//potrzebne, bo inaczej nie zawsze przerywa
        }
        else break;
    }while (i <= j);

    if(left < j)//instrukcja warunkowa sprawdzana dlatego, bo w niektorych przypadkach pivot jest jedna z 2 najmniejszych wartosci
        quickSort(left, j, array);
    if(i < right)//to samo tylko ze jedna z 2 najwiekszych
        quickSort(i, right, array);
}

int main(void)
{
    cout << "Podaj ilosc elementow tablicy: ";
    int n; cin >> n;
    int *array;
    array = new int[n];
    cout << "Podaj elementy tablicy: ";
    for (int i = 0; i < n; ++i)
        cin >> array[i];

    quickSort(0, n-1, array);

    cout << "Posortowana tablica: ";
    for (int i = 0; i < n; ++i)
        cout << array[i] << " ";
    cout << "\n";
    delete[] array;
}

