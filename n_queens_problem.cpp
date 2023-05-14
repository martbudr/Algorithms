#include <iostream>

using namespace std;

const int N_MAX = 1e3;
int n;

// make everything into a class


bool queens_places[N_MAX][N_MAX];
int risk[N_MAX][N_MAX]; // how many different queens are attacking a place on the board

void place_queen(int i, int j){
    queens_places[i][j] = true;

    for(int ii=0; ii<n; ++ii) risk[ii][j]++; // for rows
    for(int jj=0; jj<n; ++jj) risk[i][jj]++; // for columns
    // for diagonals:
    for(int k=0; k<n; ++k){
        risk[k][i+j-k]++; // k+l == i+j
        risk[k][-(i-j)+k]++; // k-l == i-j
    }
    
}

void delete_queen(int i, int j){
    queens_places[i][j] = false;

    for(int ii=0; ii<n; ++ii) risk[ii][j]--;
    for(int jj=0; jj<n; ++jj) risk[i][jj]--;
    for(int k=0; k<n; ++k){
        risk[k][i+j-k]--; // k+l == i+j
        risk[k][-(i-j)+k]--; // k-l == i-j
    }
}

void init(){
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            risk[i][j] = 0;
            queens_places[i][j] = false;
        }
    }
}

bool backtrack(int loc_n){
    if(loc_n == 0) return true;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            

            if(risk[i][j] == 0 && !queens_places[i][j]){ 
                place_queen(i, j);
                if(backtrack(loc_n-1) == true) return true;

                delete_queen(i, j);
            }
        }
    }
    return false;
}

int main(void){
    cin >> n;
    if(n == 0){
        cout << '\n';
        return 0;
    }
    if(n < 0 || n > N_MAX){
        cout << "Invalid input !" << '\n';
        return -1;
    } 

    init();
    if(!backtrack(n)){
        cout << "No solution" << '\n';
        return 0;
    }
    
    cout << "The solution:" << '\n';
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j) cout << (queens_places[i][j] ? 'Q' : '#');
        cout << '\n';
    }
}