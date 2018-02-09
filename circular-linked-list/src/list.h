/*
 * list.h
 *
 *  Created on: Feb 8, 2018
 *      Author: chadstewart
 */

#ifndef LIST_H_
#define LIST_H_

#include <string>

using namespace std;

class list
{

private:

	typedef struct node
	{
		string data;
		node* next;
		bool last;
	}* nodePtr;

	nodePtr head;
	nodePtr current;
	nodePtr temp;

public:

	list();
	void addNode(string name);
	void deleteNode(string name);
	void printList(int numOfPrintsAfterLast);

};





#endif /* LIST_H_ */
