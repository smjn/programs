#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
	long t, n;
	vector<long> vec;
	cin >> n;
	vec.push_back(-1);
	for(long i=0; i<n; i++){
		cin >> t;
		vec.push_back(t);
	}
	
	for(long i=1; i<=n; i++){
		if(vec[abs(vec[i])] > 0)
			vec[abs(vec[i])] *= -1;
		else
			cout << "Repeated:" << abs(vec[i]) << endl;
	}

	for(long i=1; i<=n; i++)
		if(vec[i] > 0) cout << "Missing:" << i << endl;
	return 0;
}
