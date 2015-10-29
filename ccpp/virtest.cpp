#include <bits/stdc++.h>

using namespace std;
class A{
	public:
		void enter(){
			cout << "A::enter()" << endl;
			show();
		}
	private:
		virtual void show(){
			cout << "A" << endl;
		}
	//friend int main();
};

class B:public A{
	private:
		void show(){
			cout << "B" << endl;
		}
};

int main(){
	//A *a = new B;
	//a->enter();
	char s1[]="hello";
	char s2[]="hello";
	cout << ((s1==s2)?"yes":"no") << endl;
	s2[6]='x';
	cout << s2 << endl;
	return 0;
}
