#include <bits/stdc++.h>

using namespace std;

//given number, find coin distribution
//subset sum ways
//dynamic programming
//backtracker
//coin change
int solve(int num, int coins[], int n, int strt){
	if(num==0)	return 1;
	if(num<0)	return 0;
	if(strt>=n)	return 0;

	return solve(num-coins[strt], coins, n, strt)+
			solve(num, coins, n, strt+1);
}

int dp[100][100];
int solve2(int num, int coins[], int n){
	for(int i=0;i<num;i++)	dp[0][i] = 1;
	for(int i=1;i<=num;i++){
		for(int j=0;j<n;j++){
			int x = (i-coins[j]>=0)?dp[i-coins[j]][j]:0;
			int y = (j>=1)?dp[i][j-1]:0;
			dp[i][j]=x+y;
		}
	}

	//cout << dp[num][n-1] << endl;
	return dp[num][n-1];
}

int main(){
	int coins[] = {1,2,3};
	cout << solve(4, coins, 3, 0) << endl;
	cout << solve2(4, coins, 3) << endl;
}
