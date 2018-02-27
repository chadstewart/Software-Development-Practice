//============================================================================
// Name        : bubble-sort-practice.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "bubble.h"

using namespace std;

int main()
{
	int array[] = {18, 2, 6, 55, 3, 9, 15, 7, 23, 21, 11, 20};
	int size = sizeof(array)/sizeof(array[0]);
	bubble sort;

	sort.printArray(array, size);
	sort.bubbleSort(array, size);
	sort.printArray(array, size);

	return 0;
}
