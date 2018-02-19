/*
 * bst.cpp
 *
 *  Created on: Jan 31, 2018
 *      Author: chadstewart
 */

#include <iostream>
#include <cstdlib>

using namespace std;

#include "bst.h"

bst::bst()
{
	rootNode = NULL;
}

bst::treeNode bst::createLeaf(int key)
{
	treeNode n = new node;
	n->key = key;
	n->leftNode = NULL;
	n->rightNode = NULL;

	return n;
}

void bst::addLeaf(int key)
{
	addLeafPrivate(key, rootNode);
}

void bst::addLeafPrivate(int key, treeNode ptr)
{
	if(rootNode == NULL)
	{
		rootNode = createLeaf(key);
	}
	else if(key < ptr->key)
	{
		if(ptr->leftNode != NULL)
		{
			addLeafPrivate(key, ptr->leftNode);
		}
		else
		{
			ptr->leftNode = createLeaf(key);
		}
	}
	else if(key > ptr->key)
	{
		if(ptr->rightNode != NULL)
		{
			addLeafPrivate(key, ptr->rightNode);
		}
		else
		{
			ptr->rightNode = createLeaf(key);
		}
	}
	else
	{
		cout << "The item " << key << " has already been added to the tree." << endl;
	}
}

void bst::printInOrder()
{
	printInOrderPrivate(rootNode);
}

void bst::printInOrderPrivate(treeNode ptr)
{
	if(rootNode != NULL)
	{
		if(ptr->leftNode != NULL)
		{
			printInOrderPrivate(ptr->leftNode);
		}

		cout << ptr->key << " ";

		if(ptr->rightNode != NULL)
		{
			printInOrderPrivate(ptr->rightNode);
		}
	}
	else
	{
		cout << "The tree is empty." << endl;
	}
}

bst::treeNode bst::returnNode(int key)
{
	return returnNodePrivate(key, rootNode);
}

bst::treeNode bst::returnNodePrivate(int key, treeNode ptr)
{
	if(ptr != NULL)
	{
		if(ptr->key == key)
		{
			return ptr;
		}
		else
		{
			if(key < ptr->key)
			{
				returnNodePrivate(key, ptr->leftNode);
			}
			else
			{
				returnNodePrivate(key, ptr->rightNode);
			}
		}
	}
	else
	{
		return NULL;
	}
}

int bst::returnRootKey()
{
	if(rootNode != NULL)
	{
		return rootNode->key;
	}
	else
	{
		return 0;
	}
}

void bst::printChildren(int key)
{
	treeNode ptr = returnNode(key);

	if(ptr != NULL)
	{
		cout << "The parent node's key is: " << ptr->key << endl;

		if(ptr->leftNode != NULL)
		{
			cout << "The left child of " << ptr->key << " is: " << ptr->leftNode->key << endl;
		}
		else
		{
			cout << "There is no left child." << endl;
		}

		if(ptr->rightNode != NULL)
		{
			cout << "The right child of " << ptr->key << " is: " << ptr->rightNode->key << endl;
		}
		else
		{
			cout << "There is no right child." << endl;
		}
	}
	else
	{
		cout << "The key " << key << " is not in the tree." << endl;
	}
}

int bst::findSmallest()
{
	return findSmallestPrivate(rootNode);
}

int bst::findSmallestPrivate(treeNode ptr)
{
	if(rootNode == NULL)
	{
		cout << "The tree is empty" << endl;
		return 0;
	}
	else
	{
		if(ptr->leftNode != NULL)
		{
			findSmallestPrivate(ptr->leftNode);
		}
		else
		{
			return ptr->key;
		}
	}
}

void bst::removeNode(int key)
{
	removeNodePrivate(key, rootNode);
}

void bst::removeNodePrivate(int key, treeNode parent)
{
	if(rootNode != NULL)
	{
		if(rootNode->key == key)
		{
			removeRootMatch();
		}
		else
		{
			if(key < rootNode->key && parent->leftNode != NULL)
			{
				if(parent->leftNode->key == key)
				{
					removeMatch(parent, parent->leftNode, true);
				}
				else
				{
					removeNodePrivate(key, parent->leftNode);
				}
			}
			else if(key > rootNode->key && parent->rightNode != NULL)
			{
				if(parent->rightNode->key == key)
				{
					removeMatch(parent, parent->rightNode, false);
				}
				else
				{
					removeNodePrivate(key, parent->rightNode);
				}
			}
			else
			{
				cout << "The key " << key << " was not found in the tree." << endl;
			}
		}
	}
	else
	{
		cout << "The tree is currently empty." << endl;
	}
}

void bst::removeRootMatch()
{
	if(rootNode != NULL)
	{
		treeNode delPtr = rootNode;
		int rootKey = rootNode->key;
		int smallestInRightSubTree;

		if(rootNode->leftNode == NULL && rootNode->rightNode == NULL)
		{
			rootNode = NULL;
			delete delPtr;
		}
		else if(rootNode->leftNode == NULL && rootNode->rightNode != NULL)
		{
			rootNode = rootNode->rightNode;
			delPtr->rightNode = NULL;
			delete delPtr;
			cout << "The root node with key " << rootKey << " was deleted." << endl;
			cout << "New root node is: " << rootNode->key << endl;
		}
		else if(rootNode->leftNode != NULL && rootNode->rightNode == NULL)
		{
			rootNode = rootNode->leftNode;
			delPtr->leftNode = NULL;
			delete delPtr;
			cout << "The root node with key " << rootKey << " was deleted." << endl;
			cout << "New root node is: " << rootNode->key << endl;
		}
		else
		{
			smallestInRightSubTree = findSmallestPrivate(rootNode->rightNode);
			removeNodePrivate(smallestInRightSubTree, rootNode);
			rootNode->key = smallestInRightSubTree;
			cout << "The root key " << rootKey << "has been overwritten by key " <<
					smallestInRightSubTree << " and is now the root key." << endl;
		}
	}
	else
	{
		cout << "Cannot delete root. There is currently no tree." << endl;
	}
}

void bst::removeMatch(treeNode parent, treeNode match, bool left)
{
	if(rootNode != NULL)
	{
		treeNode delPtr = rootNode;
		int matchKey = match->key;
		int smallestInRightSubTree;

		if(match->leftNode == NULL && match->rightNode == NULL)
		{
			delPtr = match;
			if(left == true)
			{
				parent->leftNode = NULL;
			}
			else
			{
				parent->rightNode = NULL;
			}

			delete delPtr;
			cout << "The node containing key " << matchKey << " has been deleted." << endl;
		}
		else if(match->leftNode == NULL && match->rightNode != NULL)
		{
			delPtr = match;
			if(left == true)
			{
				parent->leftNode = match->rightNode;
			}
			else
			{
				parent->rightNode = match->rightNode;
			}

			match->rightNode = NULL;
			delete delPtr;
			cout << "The node containing key " << matchKey << " has been deleted." << endl;
		}
		else if(match->leftNode != NULL && match->rightNode == NULL)
		{
			delPtr = match;
			if(left == true)
			{
				parent->leftNode = match->leftNode;
			}
			else
			{
				parent->rightNode = match->leftNode;
			}

			match->rightNode = NULL;
			delete delPtr;
			cout << "The node containing key " << matchKey << " has been deleted." << endl;
		}
		else
		{
			smallestInRightSubTree = findSmallestPrivate(match->rightNode);
			removeNodePrivate(smallestInRightSubTree, match);
			match->key = smallestInRightSubTree;
		}
	}
	else
	{
		cout << "The node could not be removed. There is currently no tree." << endl;
	}
}

bst::~bst()
{
	removeSubTree(rootNode);
}

void bst::removeSubTree(treeNode ptr)
{
	if(ptr != NULL)
	{
		if(ptr->leftNode != NULL)
		{
			removeSubTree(ptr->leftNode);
		}
		if(ptr->rightNode != NULL)
		{
			removeSubTree(ptr->rightNode);
		}

		cout << "Deleting the node containing key " << ptr->key << endl;
		delete ptr;
	}
	else
	{
		cout << "The tree is already empty." << endl;
	}
}

