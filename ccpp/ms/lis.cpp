#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> v,lis;
	while(n--){
		int temp;
		cin >> temp;
		v.push_back(temp);
		lis.push_back(1);
	}

	for(int i=1;i<v.size();i++){
		int m=0;
		for(int j=0;j<i;j++){
			if(v[i]>v[j]){
				//cout << lis[j] << " ";
				m=max(m,lis[j]);
			}
		}
		lis[i]+=m;
	}

	/*for(auto x:lis){
		cout << x << " ";
	}*/

	cout << *max_element(lis.begin(), lis.end()) << endl;

	return 0;
}
