#include<iostream>
using namespace std;

class test{
    private:
        int i;
    public:
        test(){
            i=14;
        }

        void setI(int i){
            this->i=i;
        }

        int getI(){
            return i;
        }
};

int main(){
    test obj;
	test obj3(obj);
	obj.setI(10);
	test obj2;
	obj2=obj;
    cout << obj.getI() << endl;
    cout << obj2.getI() << endl;
    obj.setI(56);
    cout << obj.getI() << endl;
    return 0;
}
