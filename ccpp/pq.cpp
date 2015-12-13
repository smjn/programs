#include <bits/stdc++.h>
#include <functional>

using namespace std;

int main(){
	priority_queue<int,vector<int>, greater<int>> pq;
	pq.push(100);
	pq.push(0);
	pq.push(90);
	pq.push(800);

	cout << pq.top();
	return 0;
}
