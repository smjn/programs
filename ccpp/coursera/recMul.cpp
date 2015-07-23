#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//recursive multiplication
//(a+b)(c+d)=ac+ad+bc+bd
//(10a+b)(10c+d)=10^2ac + 10(ad+bc) + bd
long mult(long x, long y){
	if(x==0 || y==0) return 0;	//optimize
	
	stringstream s;
	s << x << " " << y;
	string st,st2;
	s >> st >> st2;
	long lx=st.size(), ly=st2.size();
	if(lx==1 || ly==1) return x*y;

	//get bigger on left
	int m=ceil(lx/2.0);
	int n=ceil(ly/2.0);

	long a=atoi(st.substr(0,m).c_str()), b=atoi(st.substr(m).c_str());
	long c=atoi(st2.substr(0,n).c_str()), d=atoi(st2.substr(n).c_str());

	//cout << "X" << a << " "<< b << " "<< c << " "<< d << endl; 

	long ac = mult(a,c);
	long bd = mult(b,d);
	long tot = mult(a+b,c+d);

	//cout << ac << " "<< bd << " "<< tot << " "<< tot-ac-bd << endl;
	return ac*pow(10,(lx%2==1?lx-1:lx)) + (tot-ac-bd)*pow(10,lx/2) + bd;
}

int main(){
	int num1, num2;
	bool isNeg=false;
	cin >> num1 >> num2;
	if((num1<0 && num2>=0) || (num1>=0 && num2<0)) isNeg=true;
	cout << (isNeg?-1:1)*mult(num1<0?-num1:num1, num2<0?-num2:num2) << endl;
	return 0;
}
