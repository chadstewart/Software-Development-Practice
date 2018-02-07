/*
 * bst.h
 *
 *  Created on: Jan 31, 2018
 *      Author: chadstewart
 */

#ifndef BST_H_
#define BST_H_

class bst
{
	private:

		struct node
		{
			int key;
			node* leftNode;
			node* rightNode;
		};

		node* rootNode;
		node* createLeaf(int key);

	public:

		bst();

};

#endif /* BST_H_ */
