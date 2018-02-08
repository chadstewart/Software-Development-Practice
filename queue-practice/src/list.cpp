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
	n->data = addName;

	if(head != NULL)
	{
		current = head;

		while(current->next != NULL)
		{
			current = current->next;
		}

		current->next = n;
	}
	else
	{
		head = n;
	}

}

void list::deleteNode()
{
	if(head != NULL)
	{
		temp = head;
		delete head;
		head = temp->next;
	}
	else
	{
		cout << "There are currently no items to delete!" << endl;
	}
}

void list::printList()
{
	if(head != NULL)
	{
		current = head;

		while(current != NULL)
		{
			cout << current->data << endl;
			current = current->next;
		}
	}
	else
	{
		cout << "There are no items in this list!" << endl;
	}

}



