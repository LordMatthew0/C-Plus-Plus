/*
    prog2.h
    CSCI 430
    9/14/2018
    Matthew Lord
*/


#ifndef H_PROG2
#define H_PROG2


#include <algorithm>
#include <cstdlib>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <iomanip>

#define ARR_SIZE 200
#define TEST_ARR_SIZE 100
#define RND_NO_RANGE 1000
#define SEED1 1
#define SEED2 3
using std::vector;
using std::cout;

void Vectors (vector<int>& v1, vector<int>& v2, int s1, int s2);
bool linearSearch(const vector<int>& v, int x);
bool binarySearch(const vector<int>& v, int x);
int search ( const vector < int >& v1, const vector < int >& v2, bool (*p ) ( const vector < int >&, int ) );
void sortVector(vector<int>& v);
void printVector(const vector<int>& v);
void printStat(int totalSucCnt, int VectorSz);
#endif
