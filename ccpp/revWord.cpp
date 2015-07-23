#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	string buf, word;
	getline(cin, buf, '\n');

	stringstream s;
	s << buf;
	if(!s.eof()){
		s >> word;
		reverse(word.begin(), word.end());
		cout << char(toupper(word[0])) << word.substr(1);
	}

	while(!s.eof()){
		cout << " ";
		s >> word;
		reverse(word.begin(), word.end());
		cout << char(toupper(word[0])) << word.substr(1);
	}

	cout << endl;
	return 0;
}
