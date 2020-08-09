#include "prog2.h"

// Driver program to test two search algorithms - linear
// search and binary search - on vector of integers.

int main ( )
{
    // Define two empty vectors of ints for given sizes and
    // fill them by random integers for given seed values.

    vector < int > A ( ARR_SIZE ), B ( TEST_ARR_SIZE );
    Vectors ( A, B, SEED1, SEED2 );

    // Print test (1st) vector before sorting its elements.
    cout << "Random Numbers Before Sorting:\n\n";
    printVector ( A );

    // Sort test (1st) vector.
    sortVector ( A );

    // Print test (1st) vector after sorting its elements.
    cout << "\nRandom Numbers After Sorting:\n\n";
    printVector ( A );

    // Print test values from 2nd vector.
    cout << "\nRandom Numbers Searched:\n\n";
    printVector ( B );

    // Search each test value from 2nd vector in 1st vector
    // using linear search algorithm.

    cout << "\nLinear Search:\n";
    int counter1 = search ( A, B, linearSearch );
    printStat ( counter1, TEST_ARR_SIZE );

    // Search each test value from 2nd vector in 1st vector
    // using binary search algorithm.

    cout << "\nBinary Search:\n";
    int counter2 = search ( A, B, binarySearch );
    printStat ( counter2, TEST_ARR_SIZE );

    return 0;
}
