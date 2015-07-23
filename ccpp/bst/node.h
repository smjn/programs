#ifndef __NODE_H__
#define __NODE_H__
class Node
{
private:
	int m_data;
	Node* m_left;
	Node* m_right;
	Node* m_parent;

public:
	Node(int aData);
	int getData();
	void setData(int aData);
	Node* getLeft();
	void setLeft(Node* aLeft);
	Node* getRight();
	void setRight(Node* aRight);
	Node* getParent();
	void setParent(Node* aParent);
	~Node();	
};
#endif