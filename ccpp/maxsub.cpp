#include <bits/stdc++.h>

using namespace std;
//compute sum of max subsequence such that no 2 elements are adjacent

int solve(const vector<int> &v, int i, long ans){
	if(i >= v.size())	return ans;
	return max(solve(v, i+2, ans+v[i]),
			solve(v, i+1, ans));
}

int main(){
	int arr[]=//{5,  5, 10, 40, 50, 35};
				{5, 5, 10, 100, 10, 5};
	vector<int> v(arr, arr+6);
	cout << solve(v, 0, 0) << endl;
	return 0;
}
