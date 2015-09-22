#include <bits/stdc++.h>

using namespace std;

//valid parenthesis, dyke words-makePerm2
void makePerm(int op, int cp, string str){
	if(!op && !cp)	cout << str << endl;
	if(op>0)	makePerm(op-1, cp+1, str+"1");
	if(cp>0)	makePerm(op, cp-1, str+"0");
}

void makePerm2(int op, int cp, string str, int n){
	if(op+cp==n)	cout << str << endl;
	if(op<n)	makePerm2(op+1, cp, str+"1", n);
	if(cp<op)	makePerm2(op, cp+1, str+"0", n);
}

int main(){
	int len;
	cin >> len;
	//makePerm(len, 0, "");
	makePerm2(0,0,"",len);
	return 0;
}
