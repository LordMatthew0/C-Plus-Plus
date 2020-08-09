/*
Matthew Lord
z1848456
10/10/2018
Assignment 5
*/


#include "prog5.h"


using namespace std;

int main() {
    list<string> L;
    
    init_vals(L);
    int cnt = 0;
    cout << "Initial group of people" << '\n' << "-----------------------" << '\n';
    print_list(L, cnt);
    list<string>::iterator it1;
    it1 = L.begin();
    int j = 0;
    for(unsigned count = 1; L.size() > 1; count++) {
        j = (count + 3 - 1 ) % L.size();
        advance(it1, j);
        it1 = L.erase(it1);
      
        if(it1 == L.end()) {
            it1 = L.begin();
        }
        if(count % 7 == 0) {
            cout << endl << endl;
          cout << "After eliminating " << count << "th person" << '\n' << "-----------------------" << '\n';
            print_list(L,cnt);
        }
    }
}

void init_vals ( list < string >& L){
    int N,M,K;
    
    cout << "Number of people? ";
    cin >> N;
    cout << endl << "Index for elimination? ";
    cin >> M;
    cout << endl << "Index for printing? ";
    cin >> K;
    cout << endl;
    L.resize(N);
    
    generate(L.begin(), L.end(), SEQ(1));
}

void print_list ( const list < string >& L, const unsigned& cnt ){
    int count = 0;
    for (int i = 0; i < L.size(); ++i) {
        cout << L.front() << " "; 
        count++;
        if(count == 12){
            cout << endl;
            count = 0;
        }
    }
}		
