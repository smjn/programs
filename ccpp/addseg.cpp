#include<bits/stdc++.h>
#define L(i) ((i<<1)+1)
#define R(i) ((i<<1)+2)
#define P(i) ((i-1)/2)

using namespace std;

void lazyUpdate(int *seg, int *lazy, int ql, int qh, int inc, int l, int h, int pos){
	if(l>h)	return;
	if(lazy[pos]){	//some value exists which is not propagated
		seg[pos] = (seg[pos]+lazy[pos])%1000000007;
		if(l!=h){
			lazy[L(pos)] = (lazy[L(pos)]+lazy[pos])%1000000007;
			lazy[R(pos)] = (lazy[R(pos)]+lazy[pos])%1000000007;
		}
		lazy[pos] = 0;
	}

	if(ql > h || qh < l)	return;//no overlap

	//total overlap
	if(ql <= l && qh >=h){
		seg[pos] = (seg[pos]+inc)%1000000007;
		if(l!=h){
			lazy[L(pos)] = (lazy[L(pos)]+inc)%1000000007;
			lazy[R(pos)] = (lazy[R(pos)]+inc)%1000000007;
		}
		return;
	}

	int m = (l+h)/2;
	lazyUpdate(seg, lazy, ql, qh, inc, l, m, L(pos));
	lazyUpdate(seg, lazy, ql, qh, inc, m+1, h, R(pos));
	seg[pos] = (seg[L(pos)]+seg[R(pos)])%1000000007;
}

int queryLazy(int *seg, int *lazy, int ql, int qh, int l, int h, int pos){
	if(l>h)	return INT_MAX;

	if(lazy[pos]){
		seg[pos] = (seg[pos]+lazy[pos])%1000000007;
		if(l!=h){
			lazy[L(pos)] = (lazy[L(pos)]+lazy[pos])%1000000007;
			lazy[R(pos)] = (lazy[R(pos)]+lazy[pos])%1000000007;
		}
		lazy[pos] = 0;
	}

	//no overlap
	if(ql > h || qh < l)	return INT_MAX;

	//total overlap
	if(ql <= l && qh >=h)	return seg[pos];

	int m = (l+h)/2;

	return (queryLazy(seg, lazy, ql, qh, l, m, L(pos))+queryLazy(seg, lazy, ql, qh, m+1, h, R(pos)))%1000000007;
}

//pos indicated pos in segmentTree
void makeTree(int *inp, int *seg, int l, int h, int pos){
	if(l==h){
		seg[pos] = inp[l];
		return;
	}
	int m = (l+h)/2;
	makeTree(inp, seg, l, m, L(pos));	//find left child
	makeTree(inp, seg, m+1, h, R(pos));	//find right child
	seg[pos]=seg[L(pos)]+seg[R(pos)];	//create parent
}

int main(){
	int arr[] = {4,6,0,1,-8,4,5,7,8,3};	//10
	int *arr2,temp;
	//create tree
	//check power of 2
	int l = sizeof(arr)/sizeof(int);
	if(!(l&(l-1))){
		//power of 2
		temp = (l<<1)-1;

	}else{
		temp = (2<<(32-__builtin_clz(l)))-1;
	}
	arr2 = new int[temp];
	int *lazy = new int[temp];
	fill(arr2, arr2+temp, INT_MAX);
	fill(lazy, lazy+temp, 0);

	makeTree(arr, arr2, 0, l-1, 0);
	lazyUpdate(arr2, lazy, 2, 3, -6, 0, l-1, 0);
	cout << queryLazy(arr2, lazy, 2, 3, 0, l-1, 0) << endl;
	return 0;
}
