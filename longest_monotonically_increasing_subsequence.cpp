#include <iostream>
#include <vector>

using namespace std;

int binSearch(int left, int right, vector<int>& values, int array_i) {// szukanie najwiekszego indeksu za (w sensie 1 dalej) ktory mozna wstawic dana wartosc
    int mid;
    while (left < right) {
        mid = (left + right + 1) / 2;
        if (values[mid] <= array_i)
            left = mid;
        else right = mid - 1;
    }
    return left;
}

int subsequenceLength(vector<int>& array, int n) {
    if (n < 1) return 0;

    vector<int> values(n);// wartosci na koncach ciagow o danej dlugosci-1
    int length = 1;// wskazuje na pierwsze puste miejsce w ciagu

    values[0] = array[0];
    for (int i = 1; i < n; ++i) {
        if (array[i] < values[0])// najmniejsza wartosc
            values[0] = array[i];
        else if (array[i] > values[length - 1])// najwieksza wartosc
            values[length++] = array[i];
        else// wartosc gdzies pomiedzy
            values[binSearch(0, length-1, values, array[i]) + 1] = array[i];
    }
    return length;
}

int main(void)
{
    int n; cin >> n;
    vector<int> array(n);
    for (int i = 0; i < n; ++i) 
        cin >> array[i];

    cout << subsequenceLength(array, n) << '\n';
}