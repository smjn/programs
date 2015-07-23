#include <iostream>
#include "bits/stdc++.h"
#include <functional>
using namespace std;
int main(){
	int arr[] = {1,2,3,4,5,6,7,8,9};
	cout << std::count_if(arr, arr+sizeof(arr)/sizeof(int), std::bind2nd(std::greater<int>(),5));
	auto out = std::ostream_iterator<int>(std::cout, " ");
	cout << endl;
	std::transform(arr,arr+sizeof(arr)/sizeof(int), arr, [](int x){return x%2;});
	std::copy(arr,arr+sizeof(arr)/sizeof(int), out);
	std::bitset<16> b((2<<5) - 1);
	cout << b << endl;
	return 0;
}