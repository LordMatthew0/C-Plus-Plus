#include "/home/cs340/progs/18f/p8/prog8.h"


int main ( ){
    vector < int >    v1;   // heap of integers
    vector < float >  v2;   // heap of floating-pt nums
    vector < string > v3;   // heap of strings

    // print header message
    cout << "\t\t\t*** CSCI 340: Program 8 - Output ***\n\n";

    // first heap

    cout << "first heap - ascending order:\n\n";
    get_list ( v1, D1 );
    construct_heap ( v1, less < int > ( ) );
    print_list < int > print1 ( v1.size ( ), INT_SZ, INT_LN );
    for_each ( v1.begin ( ), v1.end ( ), print1 );
 
    cout << "first heap - descending order:\n\n";
    get_list ( v1, D1 );
    construct_heap ( v1, greater < int > ( ) );
    for_each ( v1.begin ( ), v1.end ( ), print1 );

    // second heap

    cout << "second heap - ascending order:\n\n";
    get_list ( v2, D2 );
    construct_heap ( v2, less < float > ( ) );
    print_list < float > print2 ( v2.size ( ), FLT_SZ, FLT_LN );
    for_each ( v2.begin ( ), v2.end ( ), print2 );

    cout << "second heap - descending order:\n\n";
    get_list ( v2, D2 );
    construct_heap ( v2, greater < float > ( ) );
    for_each ( v2.begin ( ), v2.end ( ), print2 );

    // third heap

    cout << "third heap - ascending order:\n\n";
    get_list ( v3, D3 );
    construct_heap ( v3, less < string > ( ) );
    print_list < string > print3 ( v3.size ( ), STR_SZ, STR_LN );
    for_each ( v3.begin ( ), v3.end ( ), print3 );

    cout << "third heap - descending order:\n\n";
    get_list ( v3, D3 );
    construct_heap ( v3, greater < string > ( ) );
    for_each ( v3.begin ( ), v3.end ( ), print3 );

    // print termination message
    cout << "\t\t\t*** end of program execution ***\n\n";
    
    return 0;
}

template < class T >   
void get_list ( vector < T >& v, const char* path){
    T temp;
    ifstream myfile(path);
    if(myfile.is_open()) {
        while(!myfile.eof()){
            myfile >> temp;
            v.push_back(temp);
        }
        myfile.close();
    } else {
        cout << "Unable to open file";
    }
}

template < class T, class P >
void construct_heap ( vector < T >& v, P pred ){
    make_heap(v.begin(), v.end());
    sort_heap(v.begin(), v.end(), pred);
}


template < class T > print_list < T > :: print_list ( const unsigned& s, const unsigned& w, const unsigned& l, const unsigned& c ) {
    sz = s;
    wid = w;
    len = l;
    cnt = c;
}

template < class T > void print_list < T > :: operator ( ) ( const T& x ){
      if ( cnt <= sz )
	{
		cout.width ( wid );
        cout.precision ( 2 );
        cout << fixed << showpoint;
		cout << x << " ";
		cnt++;
	}
	if(cnt % len ==0) {
	    cout << endl;
    }
	if (cnt == sz)
		cout << endl << endl;
}
