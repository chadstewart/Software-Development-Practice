/*
 * bubble.cpp
 *
 *  Created on: Feb 27, 2018
 *      Author: chadstewart
 */

#include <iostream>
#include "bubble.h"

using namespace std;

bubble::bubble()
{

}

int* bubble::bubbleSort(int* array, int size)
{
	int temp;

	for(int i = 0; i < size; i++)
	{

		for(int j = 0; j < size - i - 1; j++)
		{
			if(array[j] > array[j + 1])
			{
				temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;
			}
		}

	}

	return array;
}

void bubble::printArray(int* array, int size)
{
	for(int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}

	cout << "\n" << endl;
}


