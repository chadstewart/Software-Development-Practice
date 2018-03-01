//============================================================================
// Name        : merge-sort-practice.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "merge.h"

int main()
{
	int array[] = {18, 2, 6, 55, 3, 9, 15, 7, 23, 21, 11, 20};
	int size = sizeof(array)/sizeof(array[0]);
	merge sort;

	sort.printArray(array, size);
	sort.mergeSort(array, 0, size - 1);
	sort.printArray(array, size);

	return 0;
}
