/*
 * list.cpp
 *
 *  Created on: Feb 7, 2018
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

void list::addNode(string addName){

	nodePtr n = new node;
	n->next = NULL;
	n->previous = NULL;
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
		head = n;
	}
}

void list::deleteNode()
{
	current = head;

	if(head != NULL)
	{

		if(head->next != NULL)
		{

			while(current->next != NULL)
			{
				current = current->next;
			}

			temp = current->previous;
			temp->next = NULL;
			delete current;

		}
		else
		{
			delete current;
		}

	}
	else
	{
		cout << "There are no list items to delete!" << endl;
	}

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


