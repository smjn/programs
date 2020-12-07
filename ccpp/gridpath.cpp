#include<bits/stdc++.h>

using namespace std;

bool isGood(int tx, int ty, int n, int m);
void findPath(vector<vector<int>> &grid, pair<int,int> start, pair<int,int> end, vector<pair<int,int>> &ans);
void printPath(vector<vector<int>> &grid, pair<int,int> start, pair<int,int> end);

bool isGood(int tx, int ty, int n, int m){
    return tx >= 0 and tx < n and ty >= 0 and ty < m;
}

void findPath(vector<vector<int>> &grid, pair<int,int> start, pair<int,int> end, vector<pair<int,int>> &ans, bool &done){
    if(start.first == end.first and start.second == end.second){
        done = true;
        return;
    }

    vector<int> dx = {0, 1, 1};
    vector<int> dy = {1, 0, 1};

    for(int i=0;i<3;i++){
        int tx = start.first + dx[i];
        int ty = start.second + dy[i];

        if(isGood(tx,ty, grid.size(), grid[0].size()) and grid[tx][ty] == 0 and !done){
            ans.push_back({tx,ty});
            grid[tx][ty] = 2;
            if(!done)   findPath(grid, {tx,ty}, end, ans, done);
        }
    }
}


void printPath(vector<vector<int>> &grid, pair<int,int> start, pair<int,int> end){
    vector<pair<int,int>> ans;
    ans.push_back(start);
    bool done = false;
    findPath(grid, start, end, ans, done);
    for(auto v: ans){
        cout << v.first << " " << v.second << endl;
    }
}


int main(int argc, char *argv[]){
    vector<vector<int>> grid = {
        {0,1,0},
        {0,1,0},
        {0,0,0}
    };

    pair<int,int> start = {0,0};
    pair<int,int> end = {2,2};

    printPath(grid, start, end);
    return 0;
}
