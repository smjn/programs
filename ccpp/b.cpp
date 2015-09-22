#include <bits/stdc++.h>

using namespace std;

long gcd(long a, long b){
	if(b==0)	return a;
	return gcd(b, a%b);
}

int main(){
	int t;
	int p, e, t, m;
	int teeth[3][10000];
	long p,q;
	cin >> t;	
	for(int x=1;x<=t;x++){
		cin >> p >> e >> t;		
		for(int i=0; i<p; i++){
			cin >> teeth[0][i];
		}
		for(int i=0; i<e; i++){
			cin >> teeth[1][i];
		}
		for(int i=0; i<t; i++){
			cin >> teeth[2][i];
		}

		cin >> m;
		cout << "Case #" << x << ":" << endl;
		while(m--){
			cin >> p >> q;
			long temp=gcd(p,q);
			p/=temp;
			q/=temp;
			bool found=false;
			bool found2=false;
			for(int i=0; i<p; i++){
				for(int j=0; j<t; j++){
					long val = (teeth[0][i]%p)*(teeth[2][j]%p);
					if(!val){
						found=true;
						break;
					}
				}
				if(found)	break;
			}

			for(int i=0; i<e; i++){
				for(int j=i+1; j<e; j++){
					long val = (teeth[1][i]%p)*(teeth[1][j]%q);
					if(!val){
						found2=true;
						break;
					}
				}
				if(found2)	break;
			}

			if(found && found2)	cout << "Yes" << endl;
			else	cout << "No" << endl;
		}
	}
	return 0;
}