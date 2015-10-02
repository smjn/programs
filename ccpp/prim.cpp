#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	int n,h,a,b,w;
	cin >> t;
	
	
	while(t--){
		unordered_map<int,vector<pair<int,int>>> g;
		set<pair<int,int>> cost;
		vector<int> look;
		cin >> n >> h;
		look.push_back(-1);
		look.push_back(0);
		cost.insert(make_pair(0,1));
		
		for(int i=2;i<=n;i++){
			cost.insert(make_pair(INT_MAX,i));		
			look.push_back(INT_MAX);
		}
		
		while(h--){
			cin >> a >> b >> w;
			if(g.find(a)==g.end()){
				vector<pair<int,int>> v;
				v.push_back(make_pair(b,w));
				g[a]=v;
			}else	g[a].push_back(make_pair(b,w));
			if(g.find(b)==g.end()){
				vector<pair<int,int>> v;
				v.push_back(make_pair(a,w));
				g[b]=v;
			}else	g[b].push_back(make_pair(a,w));
		}
		
		while(!cost.empty()){
			int uc = cost.begin()->first;
			int ui = cost.begin()->second;
			
			cost.erase(cost.begin());		
			
			for(auto z:g[ui]){
				auto p = make_pair(look[z.first],z.first);
				auto it = cost.find(p);
				if(it->first>z.second){
					if(cost.find(make_pair(it->first,it->second))!=cost.end()){
						cost.erase(it);
						cost.insert(make_pair(z.second,z.first));
						look[z.first]=z.second;
					}
				}				
			}
		}
		
		long long tot=0;
		for(auto s:look){
			tot += s;
		}
		
		cout << tot+1 << endl;
	}
	
	return 0;
}
