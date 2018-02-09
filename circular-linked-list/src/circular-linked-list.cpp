//============================================================================
// Name        : circular-linked-list.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "list.h"

using namespace std;

int main() {

	list rando;

	rando.addNode("Me");
	rando.addNode("You");
	rando.addNode("Dupree");
	rando.printList(2);

	rando.deleteNode("Dupree");
	rando.printList(2);

	return 0;
}
