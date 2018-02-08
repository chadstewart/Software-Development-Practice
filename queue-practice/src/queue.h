/*
 * queue.h
 *
 *  Created on: Feb 8, 2018
 *      Author: chadstewart
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include "list.h"

class queue
{

private:

	list l;

public:

	queue();
	void push(string addName);
	void pop();

};





#endif /* QUEUE_H_ */
