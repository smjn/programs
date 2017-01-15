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

class AnotherClass{
  cout << "Hello world";
};

int main(){
    test obj;
    obj.setI(4);
    
    return 0;
}
