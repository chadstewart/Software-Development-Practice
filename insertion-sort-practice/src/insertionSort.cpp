/*
 * insertionSort.cpp
 *
 *  Created on: Feb 27, 2018
 *      Author: chadstewart
 */

#include <iostream>

#include "insertion.h"

using namespace std;

insertion::insertion()
{

}

void insertion::printArray(int* array, int size)
{
	for(int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}

	cout << "\n" << endl;
}

int* insertion::insertionSort(int* array, int size)
{
	int key;
	int j;

	for(int i = 1; i < size; i++)
	{
		key = array[i];
		j = i - 1;

		while(j >= 0 && array[j] > key)
		{
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = key;
	}

	return array;
}


