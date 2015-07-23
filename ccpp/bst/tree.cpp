#include <iostream>
#include "node.h"
#include "tree.h"

using namespace std;

Tree::Tree(){
	m_root = NULL;
	m_size = 0;
}

Node* Tree::getRoot(){
	return m_root;
}

void Tree::setRoot(Node* aRoot){
	m_root = aRoot;	
}

void Tree::insertNode(int aData){
	Node* newNode = new Node(aData);
	cout << "Inserting " << aData << endl;
	if(!getRoot()){
		setRoot(newNode);
		m_size++;
	}
	else{
		Node* temp = getRoot();
		while(temp){
			if(aData <= temp->getData()){
				if(!temp->getLeft()){
					temp->setLeft(newNode);
					temp = temp->getLeft();
					m_size++;
				}				
				temp = temp->getLeft();
			}
			else{
				if(!temp->getRight()){
					temp->setRight(newNode);
					temp = temp->getRight();
					m_size++;
				}				
				temp = temp->getRight();
			}
		}
	}
}

void Tree::printInOrder(){
	printInOrder(getRoot());
}

void Tree::printInOrder(Node *aNode){
	if(!aNode){
		return;
	}
	printInOrder(aNode->getLeft());
	cout << aNode->getData() << endl;
	printInOrder(aNode->getRight());
}

int Tree::getSize(){
	return m_size;
}

Tree::~Tree(){

}