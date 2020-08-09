/*
    Matthew Lord
    Z1848456
    Assignment 1
    prog1.cc
    9/5/2018
*/

#include "prog1.h"
using std::cout;
using std::setw;
using std::endl;
using std::sort;
using std::vector;

void genRndNums(vector<int>& v);
void printVec(const vector<int>& v);

int main(int argc, char* argv[]) {
    vector<int> v1;
    genRndNums(v1);
    sort(v1.begin(), v1.end());
    printVec(v1);
    return 0;
}

void genRndNums(vector<int>&v){
    int LOW = 1;
    int HIGH = 10000;
    int VEC_SIZE = 250;
    int SEED = 1;
    int temp = 0;
    
    srand(SEED);
    for(int i = 0; i < VEC_SIZE; i++){
        temp = rand() % HIGH + LOW;
        v.push_back(temp);
    }
}

void printVec(const vector<int>&v){
    int NO_ITEMS = 12;
    int ITEM_W = 5;
    int count = 1;
    
    for(int i = 0; i < v.size(); i++){
        if(i == count * 12){
            cout << endl;
            count++;
        }
        cout << setw(ITEM_W) << v[i] << ' ';
    }
}
