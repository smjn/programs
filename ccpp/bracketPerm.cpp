#include <bits/stdc++.h>

using namespace std;

//valid parentheses, permutation of parenthesis
void printParen(int op, int cp, string x){
	if(!op && !cp){
		cout << x << endl;
		return;
	}

	if(op>0)	printParen(op-1,cp+1,x+"(");	
	if(cp>0)	printParen(op,cp-1,x+")");
}

int main(){
	int n;
	cin >> n;
	printParen(n,0,"");
	return 0;
}
