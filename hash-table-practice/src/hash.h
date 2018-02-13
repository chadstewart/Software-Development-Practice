/*
 * hash.h
 *
 *  Created on: Feb 12, 2018
 *      Author: chadstewart
 */

#ifndef HASH_H_
#define HASH_H_

#include <iostream>
#include <string>

using namespace std;


class hash
{

private:

	static const int tableSize = 10;

	typedef struct item{
		string name;
		string favDrink;
		item* next;
	}* itemPtr;

	itemPtr hashTable[tableSize];

public:

	int hash(string key);
	void addItem(string name, string favDrink);
	int numOfItemsInIndex(int index);
	void printTable();
	void printItemsInIndex(int index);
	void findDrink(string name);
	void removeItem(string name);


};


#endif /* HASH_H_ */
