#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int arr[] = {0,0,0,0,0};
int bit[] = {0,0,0,0,0,0};

void update(int i, int v){
	for(;i<=5;i+=(i&-i))	bit[i]+=v;
}

void range(int l, int r, int v){
	update(l,v);
	update(r+1,-v);
}

int query(int i){
	int sum=0;
	for(;i>0;i-=(i&-i))	sum+=bit[i];
	return sum;
}

int main(){
	update(1,4);
	update(2,3);
	cout << query(4) << endl;
	return 0;
}
