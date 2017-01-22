#include <bits/stdc++.h>
using namespace std;
nt iteration(vector<int> array, int n){
	int iter = array.size();
	int t_ele = array[0];
	array.erase(array.begin());
	array.push_back(n);
	int cnt = array.size();
	for(int i=0;i<t_ele-cnt;i++){
		int e;
		cin >> e;
		array.push_back(e);
	}

	vector<int> temp(array.size(),0);
	for(int i=0;i<iter;i++){
		adjacent_difference(array.begin(),array.end(),temp.begin());
		array = temp;
		if(array.size()>1)	
			array.erase(array.begin());
	}
	return accumulate(array.begin(),array.end(),0);
}

int main(){
	int n;
	vector<int> vec;
	cin >> n;	//no of iterations
	for(int i=0;i<n;i++){	//first ele is number of elements
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}

	cin >> n;	//iteration+1th number
	cout << iteration(vec, n);
}
