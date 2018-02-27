//============================================================================
// Name        : insertion-sort-practice.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "insertion.h"

using namespace std;

int main()
{
	int array[] = {18, 2, 6, 55, 3, 9, 15, 7, 23, 21, 11, 20};
	int size = sizeof(array)/sizeof(array[0]);
	insertion sort;

	sort.printArray(array, size);
	sort.insertionSort(array, size);
	sort.printArray(array, size);

	return 0;
}
