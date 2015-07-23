#include<iostream>
#include<cstdlib>

using namespace std;

class A{
	public:
		A(){
			cout << "A()" << endl;
		}

		~A(){
			cout << "~A()" << endl;
		}
};

class B:public A{
	public:
		B(){
			cout << "B()" << endl;
		}

		~B(){
			cout << "~B()" << endl;
		}
};

void func(){
	B *a = new B;
	delete a;
}

int main(){
	func();
	return 0;
}
