#include <bits/stdc++.h>

using namespace std;

int main(){
	int arr[] = {5,6,1,7,9};
	deque<int> d(arr,arr+5);
	vector<int> t;
	t.assign(d.size(),0);
	adjacent_difference(d.begin(),d.end(),t.begin());
	for(auto x:t)	cout << x << " ";
	cout << accumulate(d.begin(),d.end(),0);
	return 0;
}
