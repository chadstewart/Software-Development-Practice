//============================================================================
// Name        : binary-search-tree-practice.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>

#include "bst.h"

using namespace std;

int main()
{
	int treeKeys[13] = {20, 12, 16, 4, 9, 88, 41, 2, 32, 8, 15, 17, 11};
	bst myTree;

	cout << "Print values of tree." << endl;

	myTree.printInOrder();

	for(int i = 0; i < 13; i++)
	{
		myTree.addLeaf(treeKeys[i]);
	}

	cout << "Print values of tree." << endl;

	myTree.printInOrder();

	cout << "\n\n";

	myTree.printChildren(myTree.returnRootKey());

	cout << "\n\n";

	cout << "The smallest number in the tree is: " << myTree.findSmallest() << endl;

	return 0;
}
