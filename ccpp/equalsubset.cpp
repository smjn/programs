//SAP labs, divide arrary such that sum is equal for both parts

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

map<pair<int,int>,bool> dp;
bool solvenodp(int *arr, int i, int sum){
	if(sum==0){
		return true;
	}
	if(i==0){
		return false;
	}
	if(sum<0){
		return false;
	}

	return solvenodp(arr,i-1,sum) || solvenodp(arr,i-1,sum-arr[i-1]);
}

bool solve(int *arr, int i, int sum){
	//cout << i << " " << len << " " << sum << endl;
	if(sum==0){
		return true;
	}
	if(i==0){
		return false;
	}
	if(sum<0){
		return false;
	}

	auto p = make_pair(sum,i);
	if(dp.find(p) == dp.end()){
		bool x = solve(arr,i-1,sum);
		bool y = solve(arr,i-1,sum-arr[i-1]);
		dp[p] = x||y;
	}
	return dp[p];
}

int main(){
	int arr[120],sum=0;
	for(int i=1;i<=120;i++){
		arr[i] = i;
		sum += i;
	}
	int len = sizeof(arr)/sizeof(int);
	
	if(sum%2 == 1){
		cout << "Not possible" << endl;
		return 0;
	}
	sum/=2;
	random_shuffle(arr,arr+len);
	
	bool ans = solve(arr,len,sum);
	if(ans)	cout << "Possible";
	else	cout << "Not Possible";
	return 0;
}
