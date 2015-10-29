#include <bits/stdc++.h>
using namespace std;
//pallindrom binary
//microsoft 2014
int main(){
	for(int n=0;n<200;n++){
		//cin >> n;
		if(n==0){
			cout << 0 << endl;
			continue;
		}
		if(n==1){
			cout << 1 << endl;
			continue;
		}

		//int msbP = __builtin_clz(165);
		int x=1<<30,msbP=0;

		//cout << x << endl;
		while((x&n)!=x){
			x>>=1;
			msbP++;
		}

		int l = (1<<(31-msbP-1));

		int r = 1;

		//cout << l << "   " << r;
		int s = floor(log2(n)+1);
		int t=s, c=0;
		s/=2;
		
		int flag=false;
		while(s--){
			bool bl = (l&n)==l?true:false;
			bool br = (r&n)==r?true:false;
			 
			if(bl!=br){
				cout << -1 << endl;
				flag=true;
				break;
			}else if(bl){
				c+=2;
			}
			l>>=1;
			r<<=1;
		}

		if(flag)	continue;

		if(t&1){
			l>>=1;
			if((n&l)==l)	c++;
		}
		
		cout << n << " " <<  c << endl;
	}

	return 0;
}
