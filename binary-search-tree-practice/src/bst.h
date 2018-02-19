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

		typedef struct node
		{
			int key;
			node* leftNode;
			node* rightNode;
		}* treeNode;

		treeNode rootNode;
		void addLeafPrivate(int key, treeNode ptr);
		void printInOrderPrivate(treeNode ptr);
		treeNode returnNodePrivate(int key, treeNode ptr);
		int findSmallestPrivate(treeNode ptr);
		void removeNodePrivate(int key, treeNode parent);
		void removeRootMatch();
		void removeMatch(treeNode parent, treeNode match, bool left);
		treeNode createLeaf(int key);
		treeNode returnNode(int key);
		void removeSubTree(treeNode ptr);

	public:

		bst();
		~bst();
		void addLeaf(int key);
		void printInOrder();
		int returnRootKey();
		void printChildren(int key);
		int findSmallest();
		void removeNode(int key);

};

#endif /* BST_H_ */
