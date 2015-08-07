#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isPrime(int num){
	if(num<=1)	return false;
	for(int i=2; i<=sqrt(num); i++){
		if(num%i)	return false;
	}
	return true;
}

int sieve(int num){
	if(num <= 2)	return 0;
	vector<bool> v;
	v.assign(num,true);
	v[0] = false, v[1] = false;

	for(int i=2; i<=sqrt(num); i++){
		if(v[i] && isPrime(i)){
			for(int j=i*i; j<num; j+=i)
				v[j] = false;
		}
	}
	
	return count_if(v.begin(), v.end(), [](bool x){return x;});
}

int main(){
	cout << sieve(11) << endl;
	return 0;
}
