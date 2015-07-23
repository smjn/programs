#include <iostream>
#include "node.h"

Node::Node(int aData = 0){
	m_data = aData;
	m_left = NULL;
	m_right = NULL;
	m_parent = NULL;
}

int Node::getData(){
	return m_data;
}

void Node::setData(int aData){
	m_data = aData;
}

Node* Node::getLeft(){
	return m_left;
}

void Node::setLeft(Node* aLeft){
	m_left = aLeft;
}

Node* Node::getRight(){
	return m_right;
}

void Node::setRight(Node* aRight){
	m_right = aRight;
}

Node* Node::getParent(){
	return m_parent;
}

void Node::setParent(Node* aParent){
	m_parent = aParent;
}

Node::~Node(){

}