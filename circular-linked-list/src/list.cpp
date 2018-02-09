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

	while(counter == false && current->data != nameToDelete)
	{
		if(current->last == true)
		{
			counter = true;
		}
		temp = current;
		current = current->next;
	}

	if (counter == true)
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
			temp->next = head;

			if(temp == head)
			{
				temp->next = NULL;
			}
		}

		delete delPtr;
		cout << "The item has been deleted!" << endl;

	}

}

void list::printList(int numOfPrintsAfterLast)
{

	current = head;
	int counter = -1;
	bool firstPass = false;

	if(head->last == true)
	{
		cout << "There is only one item: " << current->data << endl;
		return;
	}

	while(counter < numOfPrintsAfterLast)
	{
		if(counter != -1)
		{
			counter++;
		}
		else if(current->last == true && firstPass == false)
		{
			firstPass = true;
			counter = 0;
		}

		cout << current->data << endl;
		current = current->next;
	}

}




