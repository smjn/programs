#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//for vectot need to pass index also
void kCombination(string soFar, string rest, int k){
	if(!k)
		cout << soFar << endl;
	else{
		for(int i=0; i<rest.size(); i++)
			kCombination(soFar+rest[i], rest.substr(i+1), k-1);
	}
}

void kCombination(string input, int k){
	kCombination("", input, k);
}

int main(){
	kCombination("123456789",3);
	return 0;
}
