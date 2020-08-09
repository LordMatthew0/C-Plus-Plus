/*
    sub2.cpp
    CSCI 430
    9/14/2018
    Matthew Lord
*/

#include "prog2.h"
using std::cout;
using std::setw;
using std::endl;
using std::sort;
using std::find;
using std::binary_search;
using std::vector;

void Vectors (vector<int>& v1, vector<int>& v2, int s1, int s2){
    int LOW = 1;
    int HIGH = 1000;

    srand(s1); // initialize RNG
    v1.clear();
    for(int i=0;i<(ARR_SIZE);i++) { v1.push_back(rand() % (HIGH - LOW +1) + LOW); }

    srand(s2); // initialize RNG
    v2.clear();
    for(int i=0;i<TEST_ARR_SIZE;i++) { v2.push_back(rand( ) % (HIGH - LOW +1) + LOW); }
}

bool linearSearch(const vector<int>& v, int x){
    vector<int>::const_iterator it;
    
    it = find(v.begin(), v.end(), x);
    if(it != v.end()){
        return true;
    } else {
        return false;
    } 
}

bool binarySearch(const vector<int>& v, int x){
    
    if(binary_search(v.begin(), v.end(), x)){
        return true;
    } else {
        return false;
    }
}

int search ( const vector < int >& v1, const vector < int >& v2, bool (*p ) ( const vector < int >&, int ) ){
    int n = v2.size ( );
    int totalSucCnt = 0;

    for ( int i = 0; i < n; i++ ) {
        
        if ( p ( v1, v2[i] ) ) totalSucCnt++;

    }
    return totalSucCnt;
}

void sortVector(vector<int>& v){
    sort(v.begin(), v.end());
}

void printVector(const vector<int>& v){
    int NO_ITEMS = 16;
    int ITEM_W = 4;
    int count = 1;
    
    for(int i = 0; i < v.size(); i++){
        if(i == count * 16){
            cout << endl;
            count++;
        }
        cout << setw(ITEM_W) << v[i] << ' ';
    }
}

void printStat(int totalSucCnt, int VectorSz){
    double percent = 0;
    percent = totalSucCnt / VectorSz;
    
    cout << "Percent of Successful Searches = "<< percent << '%' << '\n';
}




