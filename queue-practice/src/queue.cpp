/*
 * queue.cpp
 *
 *  Created on: Feb 8, 2018
 *      Author: chadstewart
 */

#include "queue.h"

queue::queue()
{

}

void queue::push(string addName)
{
	l.addNode(addName);
	l.printList();
}

void queue::pop()
{
	l.deleteNode();
	l.printList();
}




