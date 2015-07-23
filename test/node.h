#ifndef NODE_H
#define NODE_H

class Node{
private:
    int m_data;
    Node *m_l;
    Node *m_r;
    Node *m_p;
public:
    Node(int aData);
    Node* getLeft();
    Node* getRight();
    Node* getParent();
    void setLeft(Node *aLeft);
    void setRight(Node *aRight);
    void setParent(Node *aParent);
    void setData(int aData);
    int getData();
};

#endif // NODE_H
