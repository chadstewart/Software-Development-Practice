/*
 * list.cpp
 *
 *  Created on: Feb 7, 2018
 *      Author: chadstewart
 */

#include <iostream>

#include "list.h"

using namespace std;

list::list()
{
	head = NULL;
	current = NULL;
}

void list::addNode(string addName){

	nodePtr n = new node;
	n->next = NULL;
	n->data = addName;

	if(head != NULL)
	{
		current = head;

		while(current->next != NULL)
		{
			current = current->next;
		}

		current->next = n;
		n->previous = current;
	}
	else
	{
		n->previous = NULL;
		head = n;
	}
}

void list::deleteNode()
{
	current = head;

	while(current->next != NULL)
	{
		current = current->next;
	}

	delete current;
}

void list::printList()
{
	current = head;

	while(current != NULL)
	{
		cout << current->data << endl;
		current = current->next;
	}

	if(head == NULL)
	{
		cout << "There are nothing in this list." << endl;
	}

}


