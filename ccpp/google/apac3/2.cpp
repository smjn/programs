#include <iostream>
#include <bits/stdc++.h>

#define f first
#define s second


using namespace std;
typedef long long ll;

int main(){
	ll t,n,p,k,ans=0,temp;
	cin >> t;
	vector<pair<ll,ll>> v;
	vector<ll> a;
	v.resize(200);
	a.resize(200);	
	for(int x=1;x<=t;x++){
		int r=-1;
		ans=0;
		v.clear();
		a.clear();
		cin >> n;
		bool can=true;
		int z=0;
		for(int i=0;i<n;i++){
			cin >> p >> k;			
			auto pa = make_pair(p,k);
			v.push_back(pa);
			if(!p || !k)
				a.push_back(-1);
			else
				a.push_back(k*100/p);

			cout << a[i] << " ";

			if(p==100)	r=i;
		}
		if(r>0){
			cout << "Case #" << x << ": " <<  a[r] << endl;
			continue;
		}	


		for(int i=0;i<v.size();i++){
			if(a[i]==-1)	continue;
			for(int j=0;j<v.size();j++){
				if(a[j]==-1)	continue;
				if(i!=j){
					temp = v[j].s*100/a[i];
					if(temp == v[j].f)	continue;
					else{
						can=false;
						break;
					}
				}
			}
			if(!can){
				can=true;
				continue;
			}
			else{
				z++;
				cout << a[i];
			}
			if(z>1)	break;
			else	ans=a[i];
		}
		if(z==1){
			cout << "Case #" << x << ": " <<  ans << endl;
		}else{
			cout << "Case #" << x << ": " << -1 << endl;
		}
	}
	return 0;
}