#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
#include<cstdlib>

using namespace std;

struct point{
	long x;
	long y;
};

int main(){
	int tests=1;
	vector<point> vec;

	while(tests != 0){
		cin>>tests;
		if(tests == 0)
			exit(0);

		for(int i=0;i<tests;i++){
			point p;
			cin>>p.x;
			cin>>p.y;
			vec.push_back(p);
		}

		long double glob = -1.0f;
		for(int i=0;i<vec.size();i++){
			long double current=0.0;
			for(int j=0;j<vec.size();j++){
				long x = vec[i].x - vec[j].x;
				long y = vec[i].y - vec[j].y;
				current += sqrt(x*x + y*y);
	//				cout << current << endl;
			}
			if(current < glob || glob == -1.0){
				glob = current;
			}
		}
		
		printf("%.6Lf",glob==-1.0?0.0:glob);
		vec.clear();
	}
	return 0;
}
