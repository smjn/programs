#ifndef __TREE_H__
#define __TREE_H__

#include "node.h"
class Tree{
private:
	Node* m_root;
	void setRoot(Node* aRoot);
	void printInOrder(Node* aNode);
	Node* getRoot();
	int m_size;

public:
	Tree();
	void insertNode(int aData);
	void printInOrder();
	int getSize();
	~Tree();
};
#endif