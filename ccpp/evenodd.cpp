#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int arr[] = {3,5,1,2,8,4,6,8,0,1};
	vector<int> vec;
	vec.assign(arr, arr+sizeof(arr)/sizeof(int));
	for(auto it = vec.begin(); it != vec.end(); it++)
		cout << *it << "\t";
	cout << endl;
	vector<int>::iterator s = vec.begin();
	vector<int>::iterator e = vec.end()-1;
	while(s<e){
		//cout << *e%2 <<  endl;
		if(!(*s%2))
			s++;
		if(*e%2)
			e--;
		if(*s%2 != 0 && *e%2 == 0)
			iter_swap(s,e);
	}
	for(auto it = vec.begin(); it != vec.end(); it++)
		cout << *it << "\t";
	cout << endl;
	return 0;
}

