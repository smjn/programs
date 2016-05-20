#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	string s = "ab cd ef";
	reverse(s.begin(), s.end());
	//s += "$";

	cout << s << endl;
	auto it1 = s.begin();
	for(auto it2=s.begin();it2!=s.end(); it2++){
		if(*it2 == ' '){
			reverse(it1, it2);
			it1 = it2+1;
		}
		else if(it2==s.end()-1){
			reverse(it1, s.end());
		}
	}

	cout << s;
	return 0;
}
