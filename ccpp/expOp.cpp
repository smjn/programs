#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<string> tot;
public:
    void solve(string seen, string rest, int target, int ans){
        //cout << ans << " " << rest << endl;
        if(rest.empty()){
            if(target==ans) tot.push_back(seen);
        }else{
            int temp=0;
            if(seen.empty()){
                seen+=to_string(rest.front()-'0');
				solve(seen, rest.substr(1), target, rest.front()-'0');
            }else{
                string t1=to_string(rest.front()-'0');
                solve(seen+"+"+t1, rest.substr(1), target, ans+(rest.front()-'0'));
                solve(seen+"-"+t1, rest.substr(1), target, ans-(rest.front()-'0'));
                solve(seen+"*"+t1, rest.substr(1), target, ans*(rest.front()-'0'));
            }
        }
    }
    
    vector<string> addOperators(string num, int target) {
        solve("", num, target, 0);
        for(auto x:tot){
            cout << x << endl;
        }
        return tot;
    }
};

int main(){
	Solution so;
	so.addOperators("232",8);
	return 0;
}

