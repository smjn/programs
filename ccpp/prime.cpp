#include <bits/stdc++.h>

using namespace std;
int countPrimes(int n) {
	if(n<=1)    return 0;
	
	vector<bool> vp;
	vp.assign(n,true);
	vp[0]=false,vp[1]=false;
	
	for(int p=2;p<=sqrt(n);p++){
		if(vp[p]){
			for(int i=p*p;i<n;i+=p)
				vp[i] = false;
		}
	}
	
	int cnt=0;
	for(int i=0;i<n;i++)
		if(vp[i])   cnt++;
	return cnt;
    
}

int main(){
	cout << countPrimes(INT_MAX) << endl;
	return 0;
}
