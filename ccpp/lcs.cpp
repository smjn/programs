#include <iostream>
#include <string>

using namespace std;

int lcs(string st1, string st2, int m, int n){
	if(!m || !n)	return 0;
	if(st1[m]==st2[n])	return 1+lcs(st1, st2, m-1, n-1);

	return max(lcs(st1, st2, m-1, n), lcs(st1, st2, m, n-1));
}

int main(){
	string st1, st2;
	cin >> st1 >> st2;

	cout << lcs(st1, st2, st1.size()-1, st2.size()-1) << endl;

	return 0;
}