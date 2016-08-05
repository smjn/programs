#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

int main(int argnum, char **args){
	int seed = atoi(args[1]);
	int iter = atoi(args[2]);
	int sc=0,nc=0;
	
	srand(seed);
	for(int j=0;j<5;j++){
		int s,n;
		s=n=0;
		for(int i=0;i<iter;i++){
			int num = rand()%100;
			s += (num%2==0)?1:0;
			n += (num%2!=0)?1:0;
		}
		sc += (s>n)?1:0;
		nc += (n>s)?1:0;
	}

	if(nc>sc)	cout << "nvidia";
	else if(nc<sc)	cout << "sap";
	else	cout << "any!";
	cout << endl;

	return 0;
}



