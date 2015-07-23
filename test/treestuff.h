#ifndef TREESTUFF_H
#define TREESTUFF_H
#include <iostream>
#include "node.h"

using namespace std;

class TreeStuff{

private:
    Node *m_root;
    int m_size;
    void addNode(int aData,Node *aNode);

public:
    TreeStuff();
    void addData(int aData);
    void printTree(Node *aNode);
    Node *getRoot();
    int getSize();
};


#endif // TREESTUFF_H
