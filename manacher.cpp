#include <iostream>
#include <vector>

using namespace std;

int znajdz_brutalnie(int lewy, int prawy, vector<char>& slowo)
{
    int dlugosc = 0, n = slowo.size();
    while(lewy>=0 && prawy<n && slowo[lewy] == slowo[prawy]){
        dlugosc++;
        lewy--;
        prawy++;
    }
    return dlugosc;
}

int main(void)
{
    int n;
    cin >> n;
    n = 2*n + 1; // zmienienie rozmiaru tak, aby zawieral tez znaki #

    vector<char> slowo(n);
    vector<int> dlugosci(n); // dlugosci palindromow o srodkach w indeksach; jesli palindrom o srodku w i jest jednoliterowy, to dlugosci[i] = 0

    // wczytywanie slowa (#a#a#...#z#z#)
    slowo[0] = '#';
    for(int i=1; i<n; i+=2){
        cin >> slowo[i];
        slowo[i+1] = '#';
    }

    int najdalej_siegajacy = 0; // indeks najdalej siegajacego
    dlugosci[0] = 0;
    for(int i=1; i<n; ++i){
        if(dlugosci[najdalej_siegajacy] + najdalej_siegajacy < i)
            dlugosci[i] = znajdz_brutalnie(i-1, i+1, slowo);
        else{
            int odpowiadajacy_i = najdalej_siegajacy - (i - najdalej_siegajacy);

            // jesli palindrom o srodku w odpowiadajacy_i zawiera sie w palindromie najdalej siegajacym
            if(odpowiadajacy_i - dlugosci[odpowiadajacy_i] < najdalej_siegajacy - dlugosci[najdalej_siegajacy])
                dlugosci[i] = dlugosci[odpowiadajacy_i];
            // jesli palindrom o srodku w odpowiadajacy_i wystaje poza palindrom najdalej siegajacy
            else if(odpowiadajacy_i - dlugosci[odpowiadajacy_i] > najdalej_siegajacy - dlugosci[najdalej_siegajacy])
                dlugosci[i] = dlugosci[najdalej_siegajacy] + najdalej_siegajacy - i;
            // jesli palindrom o srodku w odpowiadajacy_i zaczyna sie w tym samym miejscu co najdalej siegajacy
            else
                dlugosci[i] = znajdz_brutalnie(i - (najdalej_siegajacy + dlugosci[najdalej_siegajacy] - i), najdalej_siegajacy + dlugosci[najdalej_siegajacy] + 1, slowo);
        }

        if(dlugosci[i] + i > dlugosci[najdalej_siegajacy] + najdalej_siegajacy) // jesli nowy palindrom siega dalej niz stary
            najdalej_siegajacy = i; // zaktualizuj
    }

    for(int i=0; i<n; ++i)
        cout << dlugosci[i] << ' ';
    cout << '\n';
}
