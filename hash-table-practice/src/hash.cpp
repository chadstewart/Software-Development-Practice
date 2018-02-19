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

int hash::createHash(string key)
{
	int hash = 0;
	int index;
	int stringLength = key.length();

	for(int i = 0; i < stringLength; i++)
	{
		hash = hash + (int)key[i];
	}

	index = hash % tableSize;

	return index;
}

void hash::addItem(string name, string favDrink)
{
	int index = createHash(name);

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

void hash::findDrink(string name)
{
	int index = createHash(name);
	bool foundName = false;
	string drink;

	itemPtr ptr = hashTable[index];

	while(ptr != NULL)
	{
		if(ptr->name == name)
		{
			drink = ptr->favDrink;
			foundName = true;
			break;
		}
		else
		{
			ptr = ptr->next;
		}
	}

	if(foundName == true)
	{
		cout << "Favorite drink of " << name << " is: " << drink  << endl;
	}
	else
	{
		cout << name << " was not found." << endl;
	}

}

void hash::removeItem(string name)
{
	int index = createHash(name);

	itemPtr delPtr;
	itemPtr ptr1;
	itemPtr ptr2;

	//Case 0 - bucket is empty

	if(hashTable[index]->name == "empty")
	{
		cout << "Item was not found." << endl;
	}//Case 1 - only one item and has matching name
	else if(hashTable[index]->name == name && hashTable[index]->next == NULL)
	{
		hashTable[index]->name = "empty";
		hashTable[index]->favDrink = "empty";

		cout << name << " was removed from the hash table." << endl;
	}//Case 2 - first item of a bucket with multiple items
	else if(hashTable[index]->name == name && hashTable[index]->next != NULL)
	{
		delPtr = hashTable[index];
		hashTable[index] = hashTable[index]->next;
		delete delPtr;

		cout << name << " was removed from the hash table." << endl;
	}//Case 3 - bucket contains items but first item is not a match //3.1 - no match
	else if(hashTable[index]->name != name && hashTable[index]->next != NULL)
	{
		ptr1 = hashTable[index]->next;
		ptr2 = hashTable[index];

		while(ptr1 != NULL && ptr1->name != name)
		{
			ptr2 = ptr1;
			ptr1 = ptr1->next;
		}

		if(ptr1 == NULL)
		{
			cout << name << " was not found." << endl;
		}//3.2 - match found
		else
		{
			delPtr = ptr1;
			ptr1 = ptr1->next;
			ptr2->next = ptr1;

			delete delPtr;

			cout << name << " was removed from the hash table." << endl;
		}
	}




}



