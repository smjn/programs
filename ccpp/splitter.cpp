#include <bits/stdc++.h>
#include <iostream>
#include <sstream>

using namespace std;

int main(){
	vector<string> buf2;
	string buf;
	vector<int> n,p;
	string tot;
	
	getline(cin, tot, '\n');
	stringstream tots(tot);

	while(getline(tots, buf, '#')){
		buf2.push_back(buf);
	}

	stringstream ss(buf2[0]);
	int temp;
	while(ss>>temp){
		n.push_back(temp);
	}
	ss.clear();
	ss.str(buf2[1]);
	while(ss>>temp){
		p.push_back(temp);
	}

	sort(n.begin(), n.end());
	sort(p.begin(), p.end(), greater<int>());

	long long totl=0;
	for(int i=0;i<n.size();i++){
		totl += n[i]*p[i];
	}

	cout << totl << endl;

	return 0;
}