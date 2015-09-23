#include <bits/stdc++.h>

using namespace std;

//unique hats
//backtracker
//permute variable length vector of vectors
void solve( vector<vector<int>> &v, int ans[], int start, int &val){
	if(start >= v.size()){
		//for(int i=0;i<v.size();i++){
		//	cout << ans[i] << " ";
		//}
		//cout << endl;
		unordered_set<int> s(ans, ans+v.size());
		if(s.size()==v.size())	val++;
		return;
	}
	for(int j=0;j<v[start].size();j++){
		ans[start]=v[start][j];
		solve(v, ans, start+1, val);
	}
}

int main(){
	int n, temp, t2;
	cin >> n;
	cin.ignore();
	string buffer;
	stringstream ss;
	vector<vector<int>> v(n);
	for(int i=0;i<n;i++){
		ss.clear();
		getline(cin, buffer, '\n');
		ss<<buffer;
		while(ss>>t2)	v[i].push_back(t2);
	}

	int val=0;
	int arr[100];
	solve(v, arr, 0, val);
	cout << val << endl;
	return 0;
}
