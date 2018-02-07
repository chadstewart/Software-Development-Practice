/*
 * list.cpp
 *
 *  Created on: Jan 30, 2018
 *      Author: chadstewart
 */

#include <cstdlib>
#include <iostream>

#include "list.h"

using namespace std;

list::list()
{
	head = NULL;
	current = NULL;
	temp = NULL;
}

void list::addNode(int addData)
{
	nodePtr n = new node;
	n->next = NULL;
	n->data = addData;

	if (head != NULL)
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

void list::deleteNode(int delData)
{
	nodePtr delPtr = NULL;
	temp = head;
	current = head;

	while(current != NULL && current->data != delData)
	{
		temp = current;
		current = current->next;
	}

	if (current == NULL)
		{
		cout << "Data was not in the list.\n";
		delete delPtr;
	}

	if (current->data == delData)
	{
		delPtr = current;
		current = current->next;
		temp->next = current;

		if(delPtr == head)
		{
			head = head->next;
			temp = NULL;
		}

		delete delPtr;
		cout << "The value has been deleted." << endl;
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
}
