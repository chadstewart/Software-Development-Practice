/*
 * merge.cpp
 *
 *  Created on: Mar 1, 2018
 *      Author: chadstewart
 */

#include <iostream>

#include "merge.h"

using namespace std;

merge::merge()
{

}

merge::~merge()
{

}

void merge::mergeSort(int* array, int left, int right)
{
	if(left < right)
	{
		int merge = (left + (right - 1)) / 2;

		mergeSort(array, left, merge);
		mergeSort(array, merge + 1, right);

		mergeArray(array, left, merge, right);
	}
}

void merge::mergeArray(int* array, int left, int merge, int right)
{
	int i, k, j;
	int n1 = merge - left + 1;
	int n2 = right - merge;

	int Left[n1], Right[n2];

	for (i = 0; i < n1; i++)
	{
		Left[i] = array[left + i];
	}

	for (j = 0; j < n2; j++)
	{
		Right[j] = array[merge + 1 + j];
	}

	i = j = 0;
	k = left;

	while(i < n1 && j < n2)
	{
		if (Left[i] <= Right[j])
		{
			array[k] = Left[i];
			i++;
		}
		else
		{
			array[k] = Right[j];
			j++;
		}
		k++;
	}

	while(i < n1)
	{
		array[k] = Left[i];
		i++;
		k++;
	}

	while(j < n2)
	{
		array[k] = Right[j];
		j++;
		k++;
	}
}

void merge::printArray(int* array, int size)
{
	for(int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}

	cout << "\n" << endl;
}




