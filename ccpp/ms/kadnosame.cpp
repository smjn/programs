#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	vector<int> v;
	cin >> n;
	while(n--){
		int t;
		cin >> t;
		v.push_back(t);
	}

	int gmax=v[0], cmax=v[0];
	bool isRepeat=false;
	int s=0,e=0;

	for(int i=1;i<v.size();i++){
		for(int j=s; j<=e;j++){
			if(v[i]==v[j] && i!=j && s!=e){
				isRepeat = true;
				break;
			}
		}
		if(isRepeat){
			isRepeat=false;
			s=i;
			e=i;
			cmax=v[i];
			continue;
		}

		cmax=max(v[i],cmax+v[i]);
		if(cmax+v[i]>=v[i]){
			e=i;
		}else{
			s=i;
			e=i;
		}

		if(cmax>gmax){
			gmax = cmax;
		}
	}

	cout << gmax << endl;//<< " " << s << " " << e << endl;
	return 0;
}
