#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#define pii pair<int,int>
#define F first
#define S second
#define fr(i,n) for(int i=0;i<n;++i)
#define pr cout<<
#define en <<'\n'
#define sp <<' '
using namespace std;
typedef long long ll;

// int ar[200001];

int mind[100001],prm[100001]; // mind[i] = min prime divisor of i.
int pcnt=0; // count no of primes in prm.

// making sieve.
void build_sieve(int n) {
	int mi,pd,j;
	mind[1]=1;
	for (int i = 2; i <= n; ++i)
	{
		if (mind[i] == 0)
		{
			prm[pcnt++]=i;
			mind[i]=i;
		}
		j=0;
		while(j<pcnt && prm[j]<=mind[i])
		{
			if( (pd=i*prm[j]) >n) break;
			mind[pd] = prm[j];
			++j;
		}
	}
}

// making factors of N using sieve.
int divs[100][100],sz[100],cnt;
void facs(int ind,int prod)
{
	// needs divs, cnt.
	if(ind==cnt)
	{
		ll d,tmp;
		for(int i=0;i<sz[ind];++i)
		{
			d=prod*divs[ind][i];
			// d is the factor generated.
			pr d sp;
		}
	}
	else
	{
		for(int i=0;i<sz[ind];++i)
			facs(ind+1,prod*divs[ind][i]);
	}
}
int factors(int n)
{
	// max no of prime factors = 10.
	for(int i=0;i<10;++i)
	{
		sz[i]=1;
		divs[i][0]=1;
	}
	cnt=0;
	// adding factors of n.
	int num=n ,old=mind[num];
	while(mind[num]!=1) // making divs
	{
		if(mind[num]==old)
		{
			divs[cnt][sz[cnt]]=divs[cnt][sz[cnt]-1]*old;
			++sz[cnt];
			num/=old;
		}
		else
		{
			++cnt;
			old=mind[num];
		}
	}
	facs(0,1); // generating factors.
}

main()
{
	//ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t,N;
	N=60 ;
	build_sieve(100000);
	pr "No of primes: "<<pcnt en;
	// pr "least prime factor: ";fr(i,100) pr i<<" : "<<mind[i] en;
	
	factors(N);
	
	
}


