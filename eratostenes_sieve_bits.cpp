#include <bits/stdc++.h>

using namespace std;

void sito(vector<char>& V, long long n)
{
  	for(int i=0; i<=n/8; i++) V[i]=0; /// nieraz mozna wyrzucic
  	for(int i=2; i*i<=n; i++) {
    	if(!(((int)V[i>>3]>>(i&7))&1)){
            for(int j=i*i; j<=n; j+=i)
                V[j>>3] |= (1<<(j&7)); //ustawienie odpowiedniego bitu na 1
    	}
    }
}

int main(void)
{
  	ios_base::sync_with_stdio(0);
  	cin.tie(0); cout.tie(0);

  	long long n;
  	cin >> n;
  	vector<char> V(n/8 + 1);

  	sito(V, n);

  	for(int i=2; i<=n; i++){
        if(!(((int)V[i>>3]>>(i&7))&1))
      		cout << i << ' ';
  	}
  	cout << '\n';
}
