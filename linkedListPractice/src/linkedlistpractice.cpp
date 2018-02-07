//============================================================================
// Name        : linkedlistpractice.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdlib>
#include "list.h"

using namespace std;

int main() {
	list rando;

	rando.addNode(3);
	rando.addNode(5);
	rando.addNode(7);
	rando.printList();

	rando.deleteNode(1);
	rando.printList();



	return 0;
}
