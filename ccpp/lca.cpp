#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int tab[100000][17];
	
	for(int i=0; i<n; i++)
		for(int j=0; 1<<j < n; j++)
			tab[i][j]=-1;

	for(int i=0; i<n; i++)
		tab[i][0] = t[i];

	for(int j=1; i<<j < n; j++)
		for(i=0; i < n; i++)
			if(tab[i][j-1] != -1)
				tab[i][j] = tab[tab[i][j-1]][j-1];
}

int query(int n, int tab[100000][17], int t[100000], int l[100000], int p, int q){
	int temp;
	if(l[p] < l[q])
		swap(p,q);
	for(int lg = 1; 1<<lg <= l[p]; lg++);
	lg--;

	for(int i=lg; i>=0; i--)
		if(l[p] - (1<<i) >= l[q])
			p = tab[p][i];

	if(p==q)	return p;

	for(int i=lg; i>=0; i--){
		if(tab[p][i]!=-1 && tab[p][i] != tab[q][i]){
			p = tab[p][i];
			q = tab[q][i];
		}
	}

	return t[p];
}
