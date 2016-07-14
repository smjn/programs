#include <bits/stdc++.h>

using namespace std;

namespace {
	class onearg{
		private:
			int x;
		public:
			onearg(){
				x=0;
			}

			onearg(int x){
				cout << "haha" << endl;
				this->x = x;
			}

			void print(){
				cout << this->x << endl;
			}
	};

	struct node{
		int data;
	};
};

int main(){
	/*onearg obj,obj2;
	obj2.print();
	obj2=5;
	obj2.print();*/

	node *n = (node *)malloc(sizeof(node));
	cout << sizeof(*n) << endl;
	free(n);
	cout << sizeof(*n) << endl;
	free(n);
	return 0;
}
