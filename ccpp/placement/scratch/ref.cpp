#include <iostream>
#include <vector>
#include <algorithm>
#include <typeinfo>
#define all(c) c.begin(), c.end()
#define tr(container, it) \
	for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
using namespace std;


void func(const vector<int> &vec){
	tr(vec, it)
		cout << *it << endl;
}

int main(){
	vector<int> vec;
	vec.push_back(20);
	func(vec);
	int p[] = {1,2,4};
	for(int i = 0; i<3; i++){
		cout << p[i] << endl;
	}
	return 0;
}


