for(int i=1;i<=n;i++)	c[i][i]=0


for(int i=1;i<=n-1;i++){
	for(int j=1;j<n-i;j++){
		x=i+j;
		int z=0;
		for(int k=i;k<=j;k++){
			z=min(z, c[i][k] + c[k+1][j] + m[i-1]*m[k]*m[j]);
		}
		c[i][j]=z;
	}
}
