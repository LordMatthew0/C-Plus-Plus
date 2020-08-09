/*
    prog3.cpp
    CSCI 430
    9/24/2018
    Matthew Lord
*/

#include "prog3.h"


using std::set;
using std::cin;
using std::cout;
using std::setw;


void print_primes ( const set < int >& s );
void sieve ( set < int >& s, int n );

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;
    
    set<int> s;
    sieve(s, n);
    print_primes(s);
    return 0;
}

void sieve ( set < int >& s, int n ){
    for(int i = 2; i < n +1; i++)  //fill up the set
		{
			s.insert(i);
		}
	
	for(int m = 2; m < n; m++)   //test for multiples of prime numbers
		{
			for (int k = m * m; k <= n; k += m)  //remove all non prime numbers 
			{
				s.erase(k);
			}
		} 
}

void print_primes ( const set < int >& s ){
    int counter = 0;       // initialze counter
    int ITEM_W = 4;
    int NO_ITEMS = 16;
    set <int>::const_iterator it;

    cout<< '\n';
    cout << "There are " << s.size() <<" prime numbers." << '\n'; //show the number of prime numbers 
    cout<< '\n';

	for(it = s.begin(); it != s.end(); ++it) {
		cout << setw(ITEM_W) << *it;
		counter++;   // prints each element in se

		if (counter == NO_ITEMS) {
            cout << '\n';   // creates new line every NO_ITEMS
            counter = 0;   // reset the line counter
        }
	}
    cout << "\n";//prevent bad formatting in command line
    cout<< '\n';
}
