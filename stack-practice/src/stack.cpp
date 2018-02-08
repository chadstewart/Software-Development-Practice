/*
 * stack.cpp
 *
 *  Created on: Feb 7, 2018
 *      Author: chadstewart
 */

#include "stack.h"

stack::stack()
{

}

void stack::push(string addName)
{
	l.addNode(addName);
	l.printList();
}

void stack::pop()
{
	l.deleteNode();
	l.printList();
}


