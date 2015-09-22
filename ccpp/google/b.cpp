#include <bits/stdc++.h>

using namespace std;

long gcd(long a, long b){
	if(b==0)	return a;
	return gcd(b, a%b);
}

int main(){
	int test;
	int p, e, t, m,i,j;
	int teeth[3][10000];
	long px,qx;
	cin >> test;	
	for(int x=1;x<=test;x++){
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
		vector<pair<long,long>> v1,v2;
		v1.reserve(p*e);
		v2.reserve(t*e);

		for(i=0; i<p; i++){
			for(j=0; j<e; j++){
				v1.push_back(make_pair(teeth[1][j],teeth[0][i]));
			}
		}
		for(i=0; i<t; i++){
			for(j=0; j<e; j++){
				v2.push_back(make_pair(teeth[1][j],teeth[2][i]));
			}
		}
		while(m--){
			cin >> px >> qx;
			bool found=false;
			for(int i=0;i<v1.size();i++){
				for(int j=0;j<v2.size();j++){
					if(v1[i].first!=v2[j].first){
						if(v1[i].first*v1[i].second*qx == v2[j].first*v2[j].second*px){
							cout << "Yes" << endl;
							found=true;
							break;
						}
					}
				}
				if(found)	break;
			}
			if(!found)	cout << "No" << endl;
		}
	}
	return 0;
}