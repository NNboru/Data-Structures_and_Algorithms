// #include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cmath>
/*
#include<vector>
#include<set>
#include<map>
*/
#define pii pair<int,int>
#define F first
#define S second
#define fr(i,n) for(int i=0;i<n;++i)
#define pr cout<<
#define en <<'\n'
#define sp <<' '
# define MOD 1000000007
using namespace std;
typedef long long ll;

ll comb[1001][1001],sumcomb[1001][1001];


// making combinations(ncr) and sum of combinations (nc0 ... ncr)%MOD;
void createComb(){
	for(int i=0;i<1001;i++)
	{
		comb[i][0]=1;
		comb[i][i]=1;
		sumcomb[i][0]=1;
	}
	for(int i=2;i<1001;i++)
		for(int j=1;j<i;j++)
			comb[i][j]=(comb[i-1][j-1]+comb[i-1][j])%MOD;
	
	// creating sumOfCombinations
	for(int i=1;i<1001;i++)
		for(int j=1;j<=i;j++)
			sumcomb[i][j]=(sumcomb[i][j-1]+comb[i][j])%MOD;
}

main()
{
	// ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t=1,n ;
	createComb();
	
	pr comb[10][2] sp<< comb[5][4];
	
	
}

/*
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
*/


