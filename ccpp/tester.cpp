#include <iostream>
#include <vector>
using namespace std;

class tester{
	private:
		int x;
		std::vector<int> v;
	public:
		tester(){
			x=0;
		}

		~tester(){
			cout<<"Destruction!!";
		}

		void doSomething(){
			cout << "hello";
		}
};

int main(){
	tester obj;
	obj.doSomething();
	return 0;
}
