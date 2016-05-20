#include <iostream>
#include "bits/stdc++.h"
using namespace std;

class tree{

	public:
		class node{
			public:
				node *left;
				node *right;
				int val;

				node(int val){
					this->left = nullptr;
					this->right = nullptr;
					this->val = val;
				}
		};

		tree::node *root;

		tree(){
			root = nullptr;
		}
		tree::node *insert(int val);
		tree::node *insertBinary(int val);
		void printInOrder(tree::node *from);
		bool isBST();

	private:
		void isBST(tree::node *root, int p, bool &ans);

};

typedef tree::node tnode;

//return pointer to added row;
tnode * tree::insert(int val){
	tnode *temp = new tnode(val);
	if(this->root==nullptr){
		this->root = temp;
		return temp;
	}

	tnode *trav = this->root, *prev=nullptr;
	while(trav!=nullptr){
		prev = trav;
		if(val<=trav->val)
			trav = trav->left;
		else
			trav = trav->right;
	}

	if(val<=prev->val)	prev->left = temp;
	else	prev->right = temp;
	return temp;
}

tnode* tree::insertBinary(int val){
	tnode *temp = new tnode(val);
	if(this->root==nullptr){
		this->root = temp;
		return temp;
	}

	tnode *trav = this->root;
	while(trav!=nullptr){
		if(trav->left == nullptr){
			trav->left = temp;
			return temp;
		}
		else if(trav->right == nullptr){
			trav->right = temp;
			return temp;
		}
		if(trav->left)	trav = trav->left;
		if(trav->right)	trav = trav->right;
	}

	return nullptr;	//will never happen
}

void tree::printInOrder(tnode *from){
	if(from==nullptr)	return;
	printInOrder(from->left);
	cout << from->val << " ";
	printInOrder(from->right);
}

void tree::isBST(tnode *root, int &p, bool &ans){
	if(!ans)	return;
	if(root==nullptr)	return;
	isBST(root->left, p, ans);
	if(p==INT_MIN)	p=root->val;
	else if(ans){
		if(root->val < p){
			//cout << root->val << " " << p << endl;
			ans = false;
		}
	}
	isBST(root->right, p, ans);
}

bool tree::isBST(){
	bool ans = true;
	int p = INT_MIN;
	isBST(this->root, p, ans);
	return ans;
}

int main(){
	tree obj;
	vector<int> v = {1,2,3,4,5,6,7,8};
	random_shuffle(v.begin(), v.end());
	for(auto x:v){
		cout << x << " ";
		obj.insert(x);
		//obj.insertBinary(x);
	}
	cout << endl;
	obj.printInOrder(obj.root);
	cout << endl;
	cout << "is bst? " << (obj.isBST()?"true":"false") << endl;
	return 0;
}
