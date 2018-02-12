/*
 * hash.cpp
 *
 *  Created on: Feb 12, 2018
 *      Author: chadstewart
 */

#include "hash.h"

hash::hash()
{
	for(int i = 0; i < tableSize; i++)
	{
		hashTable[i] = new item;
		hashTable[i]->name = "empty";
		hashTable[i]->favDrink = "empty";
		hashTable[i]->next = NULL;
	}
}

int hash::hash(string key)
{
	int hash = 0;
	int index ;

	for(int i = 0; i < index; i++)
	{
		hash = hash + (int)key[i];
	}

	index = hash % tableSize;

	return key;
}

void hash::addItem(string name, string favDrink)
{
	int index = hash(name);

	if(hashTable[index]->name == "empty")
	{
		hashTable[index]->name = name;
		hashTable[index]->favDrink = favDrink;
	}
	else
	{
		itemPtr ptr = hashTable[index];
		itemPtr n = new item;
		n->name = name;
		n->favDrink = favDrink;
		n->next = NULL;

		while(ptr->next != NULL)
		{
			ptr = ptr->next;
		}

		ptr->next = n;
	}

}

int hash::numOfItemsInIndex(int index)
{
	int count = 0;

	if(hashTable[index]->name == "empty")
	{
		return count;
	}
	else
	{
		count++;
		itemPtr ptr = hashTable[index];

		while(ptr->next != NULL)
		{
			count++;
			ptr = ptr->next;
		}

	}

	return count;
}

void hash::printTable()
{
	int number = 0;

	for(int i = 0; i < tableSize; i++)
	{
		number = numOfItemsInIndex(i);
		cout << "----------------------\n";
		cout << "Current index: " << i << endl;
		cout << hashTable[i]->name << endl;
		cout << hashTable[i]->favDrink << endl;
		cout << "No. of items: " << number << endl;
		cout << "----------------------\n";
	}

}

void hash::printItemsInIndex(int index)
{
	itemPtr ptr = hashTable[index];

	if(ptr->name == "empty")
	{
		cout << "Index " << index << " is empty." << endl;
	}
	else
	{
		cout << "Index " << index << " contains the following items: " << endl;

		while(ptr != NULL)
		{
			cout << "----------------------\n";
			cout << ptr->name << endl;
			cout << ptr->favDrink << endl;
			cout << "----------------------\n";
			ptr = ptr->next;
		}

	}

}



