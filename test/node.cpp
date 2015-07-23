#include "node.h"
#include <iostream>

using namespace std;

Node::Node(int aData){
    m_data=aData;
    m_l=NULL;
    m_r=NULL;
    m_p=NULL;
}

Node* Node::getLeft(){
    return m_l;
}

Node* Node::getRight(){
    return m_r;
}

Node* Node::getParent(){
    return m_p;
}

void Node::setLeft(Node *aLeft){
    m_l=aLeft;
}

void Node::setRight(Node *aRight){
    m_r=aRight;
}

void Node::setParent(Node *aParent){
    m_p=aParent;
}

void Node::setData(int aData){
    m_data=aData;
}
int Node::getData(){
    return m_data;
}
