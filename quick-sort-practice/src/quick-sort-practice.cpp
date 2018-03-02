//============================================================================
// Name        : quick-sort-practice.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "quick.h"

int main()
{
        int array[] = {18, 2, 6, 55, 3, 9, 15, 7, 23, 21, 11, 20};
        int size = sizeof(array)/sizeof(array[0]);
        quick sort;

        sort.printArray(array, size);
        sort.quickSort(array, 0, size - 1);
        sort.printArray(array, size);

        return 0;
}
