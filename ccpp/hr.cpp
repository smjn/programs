#include <iostream>
#include <algorithm>
#include <iterator>
#include <functional>
#include <bits/stdc++.h>

using namespace std;

unordered_map<string, vector<string> > dict;
int main()
{
	int x;
	string a,b;
    cin >> x;
    int tests = (1<<x) - 1;
    
    while(tests--){   
    	cin >> a >> b;
		//cout << a << " " << b << endl;
    	if(dict.find(a)!=dict.end()){
    		dict[a].push_back(b);    		
    	}else{
    		vector<string> v;
    		v.push_back(b);
    		dict[a] = v;
    	}
    }

	//cout << dict.size();

	for(auto p:dict){
    	for(auto l:p.second){
			if(dict.find(l)!=dict.end()){
				vector<string> s;
				dict[l] = s;
			}
    	}
    }
    
    string winner;
    int s=0;
    for(auto p:dict){
		cout << p.first << " " << p.second.size();
    	if(s<p.second.size()){
			cout << p.first;
    		s=p.second.size();
    		winner=p.first;
    	}
    }    
    cout << winner;
    return 0;
}
