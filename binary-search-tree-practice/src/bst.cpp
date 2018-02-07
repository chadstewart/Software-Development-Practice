/*
 * bst.cpp
 *
 *  Created on: Jan 31, 2018
 *      Author: chadstewart
 */
#include <iostream>
#include <cstdlib>

#include "bst.h"

bst::bst()
{
	rootNode = NULL;
}

bst::node* bst::createLeaf(int key)
{
	node* n = new node;
	n->key = key;
	n->leftNode = NULL;
	n->rightNode = NULL;

	return n;
}

