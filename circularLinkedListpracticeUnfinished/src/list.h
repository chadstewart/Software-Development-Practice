/*
 * list.h
 *
 *  Created on: Jan 30, 2018
 *      Author: chadstewart
 */

#ifndef LIST_H_
#define LIST_H_

class list
{
private:

	typedef struct node
	{
		int data;
		node* next;
	}* nodePtr;

	nodePtr head;
	nodePtr current;
	nodePtr temp;

public:

	list();
	void addNode(int addData);
	void deleteNode(int delData);
	void printList();

};

#endif /* LIST_H_ */
