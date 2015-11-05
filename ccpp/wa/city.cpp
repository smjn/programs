#include <bits/stdc++.h>

using namespace std;

typedef unordered_map<int,vector<int>> graph_t;
typedef unordered_set<int> usi_t;

//globals
int arr[100001];

void constructGraph(graph_t &graph, int n){
	while(n--){
		int a,b;
		cin >> a >> b;
		if(graph.find(a)==graph.end()){
			vector<int> v;
			v.push_back(b);
			graph[a] = v;
		}else{
			graph[a].push_back(b);
		}
		if(graph.find(b)==graph.end()){
			vector<int> v;
			v.push_back(a);
			graph[b] = v;
		}else{
			graph[b].push_back(b);
		}
	}
}

void resetDistances(){
	for(register int i=0;i<100001; i++)	arr[i] = INT_MAX;
}

int bfs(graph_t &graph, usi_t &fCities, int v){
	queue<int> q;
	q.push(v);	
	resetDistances();

	arr[v] = 0;
	while(!q.empty()){
		int curr = q.front();
		q.pop();
		for(int adj:graph[curr]){
			if(arr[adj]==INT_MAX){
				q.push(adj);
				arr[adj] = arr[curr] + 1;
			}
			if(fCities.find(adj) != fCities.end())	return arr[adj];
		}
	}

	return -1;	//should never happen
}

void handleQueries(graph_t &graph, usi_t &fCities, int m){
	int q,c;
	while(m--){				
		cin >> q >> c;
		if(q==1)	fCities.insert(c);
		else{
			if(fCities.find(m)!=fCities.end())	cout << 0 << endl;
			else	cout << bfs(graph, fCities, c) << endl;
		}
	}
}

int main(){
	graph_t graph;
	usi_t fCities;

	int n,m;

	cin >> n >> m;

	constructGraph(graph, n-1);	
	fCities.insert(1);	//first is always festive
	handleQueries(graph, fCities, m);
	return 0;
}