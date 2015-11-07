#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

LL gmax;

enum states{
	VALID=1,
	BLOCKED=-1,
	VISITED=-2
};

struct cell{
	int val;
	states state;
};

typedef vector<vector<cell>> VVC;

bool isReachable(VVC &grid){
	int m=grid[0].size(), n=grid.size();

	for(int c=0;c<m;c++){
		int cnt=0;
		for(int r=0;r<n;r++){
			if(grid[r][c].state==BLOCKED)	cnt++;
		}

		if(cnt==n){	//col not reachable
			return false;
		}
	}
	return true;
}

void findMax(VVC &grid, LL mx, int i, int j){
	if(i>=grid.size() || j>=grid[0].size())
		return;
	if(grid[i][j].state!=VALID){	//visited or blocked
		return;
	}

	if(j==grid[0].size()-1){
		gmax=max(gmax, mx+grid[i][j].val);
		grid[i][j].state=VISITED;
		findMax(grid, mx+grid[i][j].val, i-1,j);
		findMax(grid, mx+grid[i][j].val, i+1,j);
		if(i==0){	//teleport
			findMax(grid, 0, grid.size()-1, j);
		}else if(i==grid.size()-1){
			findMax(grid, 0, 0, j);
		}
		grid[i][j].state=VALID;
	}else{
		grid[i][j].state=VISITED;
		findMax(grid, mx+grid[i][j].val, i+1, j);
		findMax(grid, mx+grid[i][j].val, i-1, j);
		findMax(grid, mx+grid[i][j].val, i, j+1);
		if(i==0){	//teleport
			findMax(grid, 0, grid.size()-1, j);
		}else if(i==grid.size()-1){
			findMax(grid, 0, 0, j);
		}
		grid[i][j].state=VALID;
	}
}

int main(){
	int n,m;
	cin >> n >> m;

	VVC grid;

	for(int i=0;i<n;i++){
		vector<cell> v;
		for(int j=0;j<m;j++){
			int temp;
			cin >> temp;
			states x;
			if(temp==-1)	x=BLOCKED;
			else	x=VALID;
			cell c = {temp, x};
			v.push_back(c);
		}
		grid.push_back(v);
	}

	if(!isReachable(grid)){
		cout << -1 << endl;
		return 0;	//exit program
	}

	gmax=INT_MIN;
	for(int i=0;i<n;i++)	findMax(grid, 0, i, 0);
	cout << gmax << endl;
	return 0;
}