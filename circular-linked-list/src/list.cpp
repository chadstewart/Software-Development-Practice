/*
 * list.cpp
 *
 *  Created on: Feb 8, 2018
 *      Author: chadstewart
 */

#include <iostream>

#include "list.h"

list::list()
{
	head = NULL;
	current = NULL;
	temp = NULL;
}

void list::addNode(string addName)
{
	nodePtr n = new node;
	n->next = NULL;
	n->last = true;
	n->data = addName;

	if(head != NULL)
	{
		current = head;

		while(current->last == false)
		{
			current = current->next;
		}

		current->next = n;
		current->last = false;
		n->next = head;
	}
	else
	{
		head = n;
	}
}

void list::deleteNode(string nameToDelete)
{
	nodePtr delPtr = NULL;
	bool counter = false;
	temp = head;
	current = head;

	do{
		if(counter == false)
		{
			counter = true;
		}
		temp = current;
		current = current->next;
	}while(current != head && current->data != nameToDelete);

	if (current == head && counter == true)
	{
			cout << "Data was not in the list.\n";
			delete delPtr;
	}

	if(current->data == nameToDelete)
	{
		delPtr = current;

		if(delPtr->next != NULL)
		{
			current = current->next;
			temp->next = current;
		}

		if(delPtr->last == true)
		{
			temp->last = true;

			if(temp == head)
			{
				temp->next = NULL;
			}
		}

		delete delPtr;
		cout << "The item has been deleted!" << endl;

	}

}

bool list::printList(int numOfPrintsAfterLast)
{

	current = head;
	int counter = NULL;

	if(head->last == true)
	{
		return true;
	}

	while(counter > numOfPrintsAfterLast)
	{
		if(counter != NULL)
		{
			counter++;
		}

		if(current->last == true)
		{
			counter = 0;
		}

		cout << current->data << endl;
		current = current->next;
	}

	return false;
}




