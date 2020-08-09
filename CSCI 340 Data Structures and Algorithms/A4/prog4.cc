/*
Matthew Lord
z1848456
10/2/2018
Assignment 4 
*/

#include "prog4.h"

using namespace std;

void get_words(map<string, int>& m);
void clean_entry(const string& not_clean, string& clean);
void low(char& x);
void print_words(const map<string, int>& m);

int main(int argc, char** argv) {
   // if ( argc < 2 ) {
    //    cout << "command line argument: input-file-name" << endl;
    //    return 1;
   // }

    //ifstream infile(argv[1], ios::in);

    map<string, int> m;

    get_words( m);


    print_words( m );
    cout << "hello";
    return 0;
}

void get_words(map<string, int>& m) {
    string clean, not_clean;
    map<string, int>::const_iterator mit;                //map iterator
    
    ifstream infile( "prog4.d" , ios::in);

    infile >> clean;		//store the inputfile into string clean to be iterated

    while(!infile) {
        not_clean = "";			//initialize notclean

	    clean_entry(clean, not_clean);	//call clean entry to store words

		if(not_clean.length()>0) {
		    m[not_clean]++;
		}
	infile >> clean;
	} 
}

void clean_entry(const string& not_clean, string& clean) {
    unsigned int start;
    string temp;
    for ( start = 0; start < not_clean.length(); start ++) {
	    if( isalnum (not_clean[start] ) )break ;      //check for words with symbols
    }
    unsigned int end;
    for ( end = start; end < not_clean.length(); end++) {
	    if ( !isalnum( not_clean[end] ) )break;		//check for the words without symbols
	}

    clean = not_clean.substr(start, end-start);		//store the words into a substring

    for_each(clean.begin(), clean.end(), low);		//convert the words to lowercase
}

void low(char& x) {
    x=tolower(x);
}

void print_words(const map<string, int>& m) {
    int end_line = 0;
    int clean_words = 0;		//clean words to store
    int ITEM_W = 3;
    int NO_ITEMS = 16;

    map<string, int>::const_iterator printit;	//declare an iterator to print


	for(printit = m.begin(); printit!= m.end(); printit++) {                                        //printing formatting for a map
		cout << left << setw(ITEM_W) << printit->first << "= " << setw(NO_ITEMS) << printit->second;
		end_line++;		//increment count to reset the line
		clean_words += printit->second;	//move through the map
	    if(end_line == 3) { 
		    cout << endl; 
		    end_line = 0; 
       	}
	}
    cout << endl << "Number of words in input stream: " << clean_words << endl;  //find the number of clean words in input
    cout <<  "Number of words in outputlist: " << m.size() << endl;			//and the total number of clean words in output
}











