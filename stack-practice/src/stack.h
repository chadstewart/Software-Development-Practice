/*
 * stack.h
 *
 *  Created on: Feb 7, 2018
 *      Author: chadstewart
 */

#ifndef STACK_H_
#define STACK_H_

#include "list.h"

class stack
{

private:

	list l;

public:

	stack();
	void push(string addName);
	void pop();

};



#endif /* STACK_H_ */
