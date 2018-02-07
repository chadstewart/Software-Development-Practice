/*
 * stack.cpp
 *
 *  Created on: Feb 7, 2018
 *      Author: chadstewart
 */

#include <iostream>

#include "stack.h"

using namespace std;

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


