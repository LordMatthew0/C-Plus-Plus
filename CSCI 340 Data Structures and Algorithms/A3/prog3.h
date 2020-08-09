/*
    prog3.h
    CSCI 430
    9/24/2018
    Matthew Lord
*/


#ifndef H_PROG3
#define H_PROG3

#include <iostream>
#include <set>
#include <iomanip>

using std::set;
using std::cin;
using std::cout;
using std::setw;

void print_primes ( const set < int >& s );
void sieve ( set < int >& s, int n );

#endif