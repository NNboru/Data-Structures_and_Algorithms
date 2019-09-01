# define MOD 1000000007
{//making combinations.
ll comb[1001][1001],sumcomb[1001][1001];
ll valuesumcomb(int n,int r1,int r2)
{
	if(r2<0 or r1>n or r1>r2)
		return 0;
	if(r2>n)
		r2=n;
	if(r1<=0)
		return sumcomb[n][r2];
	return sumcomb[n][r2]-sumcomb[n][r1-1];
}

	fr(i,1001)
	{
		comb[i][0]=1;
		comb[i][i]=1;
		sumcomb[i][0]=1;
	}
	for(int i=2;i<1001;i++)
		for(int j=1;j<i;j++)
			comb[i][j]=(comb[i-1][j-1]+comb[i-1][j])%MOD;
	for(int i=1;i<1001;i++)
		for(int j=1;j<=i;j++)
			sumcomb[i][j]=(sumcomb[i][j-1]+comb[i][j])%MOD;
}