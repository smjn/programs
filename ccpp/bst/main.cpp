#include <iostream>
#include "tree.h"
#include "node.h"

using namespace std;

int main(int aArgnum, char* aArgs[]){
	Tree obj;
	obj.insertNode(12);
	obj.insertNode(1);
	obj.insertNode(7);
	obj.insertNode(-1);
	obj.insertNode(6);
	obj.insertNode(2);
	cout << "Size: " << obj.getSize() << endl;
	cout << "Traversing In order" << endl;
	obj.printInOrder();
	return 0;
}