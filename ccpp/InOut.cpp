#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main(){
	fstream obj;	
	char x[100];
	obj.open("sample.txt",ios_base::in|ios_base::out);
	obj<<"Hello There";
	obj.flush();
	obj>>x;
	cout<<x;
	obj.close();
	return 0;
}
