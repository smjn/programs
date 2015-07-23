#include <iostream>
#include <cstdlib>
#include "treestuff.h"
#include "node.h"

using namespace std;

void TreeStuff::addNode(int aData,Node *aNode){
    Node *temp = m_root;
    if(temp==NULL){
        Node *node=(Node *)malloc(sizeof(Node));
        node->setData(aData);
        temp=node;
        return;
    }
    while(temp!=NULL){
        if(aData <= temp->getData()){
            if(temp->getLeft()==NULL){
                Node *node=(Node *)malloc(sizeof(Node));
                node->setData(aData);
                temp->setLeft(node);
                node->setParent(temp);
                break;
            }
            else
                temp=temp->getLeft();
        }
        else{
            if(temp->getRight()==NULL){
                Node *node=(Node *)malloc(sizeof(Node));
                node->setData(aData);
                temp->setRight(node);
                node->setParent(temp);
                break;
            }
            else
                temp=temp->getRight();
        }
    }
}

    TreeStuff::TreeStuff(){
        m_root=NULL;
        m_size=0;
    }

    void TreeStuff::addData(int aData){
        addNode(aData,getRoot());
    }

    void TreeStuff::printTree(Node *aNode){
        Node *temp=aNode;
        while(temp!=NULL){
            cout << temp->getData();
            temp=temp->getLeft();
        }
    }

    Node* TreeStuff::getRoot(){
        return m_root;
    }

    int TreeStuff::getSize(){
        return m_size;
    }

int main(){
    TreeStuff obj;
    obj.addData(3);
    obj.addData(4);
    obj.printTree(obj.getRoot());
}
