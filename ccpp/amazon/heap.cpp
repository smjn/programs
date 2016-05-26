#include <bits/stdc++.h>
#define PARENT(i)	((i-1)>>1)

using namespace std;

void minHeapify(vector<int> &v, int pos){
	int l = (pos<<1) + 1;
	int r = (pos<<1) + 2;
	int small = pos;

	if(l < v.size() && v[l]<v[pos]){
		small = l;
	}
	if(r < v.size() && v[r]<v[pos]){
		small = r;
	}

	if(small != pos){
		swap(v[small], v[pos]);
		minHeapify(v, small);
	}
}

void decreaseKey(vector<int> &v,int i,int key){
	if(key>v[i])	return;
	v[i] = key;
	while(i>0 && v[PARENT(i)] > v[i]){
		swap(v[PARENT(i)], v[i]);
		i=PARENT(i);
	}
}

void print(vector<int> v){
	for(auto x:v){
		cout << x << " ";
	}
	cout << endl;
}

int main(int argc, char const *argv[])
{
	vector<int> v = {8,1,4,2,7,4,3,9};
	auto func = [](int a, int b){return a>b;};

	// cout << v.front() << endl;
	make_heap(v.begin(), v.end(), func);	//build min heap
	// cout << v.front() << endl;

	v.push_back(-1);
	push_heap(v.begin(), v.end(), func);	//insert at end and call heapify
	// cout << v.front() << endl;	

	pop_heap(v.begin(), v.end(), func);		//move top to last reduce size by 1 and heapify
	// cout << v.back() << endl;
	v.pop_back();
	// cout << v.front() << endl;

	print(v);
	decreaseKey(v, 2, -20);
	print(v);
	

	return 0;
}