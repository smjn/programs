#include <bits/stdc++.h>

using namespace std;

struct node{
	int val;
	node *left;
	node *right;
};

node *pre2tree(int pre[], int &pi, int s, int e, int len){
	if(pi>=len)	return nullptr;
	node *root = nullptr;

	if(pre[pi]>s && pre[pi]<e){
		root = new node;
		root->val = pre[pi];

		pi++;

		if(pi<len){
			root->left = pre2tree(pre, pi, s, root->val, len);
			root->right = pre2tree(pre, pi, root->val, e, len);
		}		
	}

	return root;
}

void inorder(node *root){
	if(root!=nullptr){
		inorder(root->left);
		cout << root->val << " ";
		inorder(root->right);
	}
}

int main(){
	int arr[] = {10,5,1,7,40,50}, pi=0;
	node *root = pre2tree(arr, pi, INT_MIN, INT_MAX, sizeof(arr)/sizeof(int));
	inorder(root);
	return 0;
}