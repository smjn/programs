#include<bits/stdc++.h>

using namespace std;

int main(){
	string buffer;
	getline(cin,buffer);
	int num1,num2;
	string s1;
	stringstream ss(buffer);
	ss >> num1 >> s1 >> num2;
	cout << num1 << endl << num2 << endl << s1;
	return 0;
}
