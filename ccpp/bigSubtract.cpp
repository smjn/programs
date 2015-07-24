#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

class BigNum{
	private:
		string num;
	public:
		BigNum(LL num){
			stringstream s;
			s<<num;
			s>>(this->num);
		}

		BigNum(string num){
			this->num = num;	
		}

		void setNum(string num){
			this->num = num;
		}

		string getNum(){
			return num;
		}

		BigNum operator-(const BigNum &num2){
			string temp="";
			if(num.size() > num2.num.size()){
				string pad(num.size()-num2.num.size(),'0');
				temp += pad;
			}
			temp += num2.num;
			string result(temp.size(),'0');
			//cout << temp << " " << result << endl;

			//find 9s complement
			for(string::iterator i=temp.begin(); i!=temp.end(); i++)
				*i = '9'-*i+'0';

			//cout << temp << endl;

			//add to invoker
			auto i=num.rbegin();
			auto j=temp.rbegin();
			auto k=result.rbegin();


			int carry=0, sum=0;
			//cout << num << endl << temp << endl;
			while(i!=num.rend()){
				sum = (*i-'0') + (*j-'0') + carry;
				//cout << sum << endl;
				if(sum>=10){
					carry=1;
					sum-=10;
				} else{
					carry=0;
				}
				//cout << sum << endl;
				*k=sum+'0';

				i++;
				j++;
				k++;
			}
			//cout << result << " " << carry << endl;
			if(!carry){
				//negative of 9s complement of result
				for(auto x=result.begin(); x!=result.end(); x++)
					*x = '9'-*x+'0';

				result="-"+result;
			} else{
				auto x=result.rbegin();
				while(x!=result.rend()){
					sum = (*x-'0') + carry;
					if(sum>=10){
						carry=1;
						sum-=10;
					}else{
						carry=0;
					}
					*x=sum+'0';
					x++;
				}
				
				auto y=result.begin();
				while((*y)=='0') y++;
				result.erase(result.begin(),y);
			}

			return BigNum(result);
		}
};

int main(){
	string buf;
	LL num1, num2;
	getline(cin, buf, '\n');
	stringstream s;
	s << buf;
	s >> num1 >> num2;
	BigNum obj1(num1), obj2(num2), obj3(1);
	obj3 = obj1-obj2;
	cout << obj3.getNum() << endl;
	return 0;
}
