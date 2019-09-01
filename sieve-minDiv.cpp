#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#define pii pair<int,int>
#define F first
#define S second
#define fr(i,n) for(int i=0;i<n;i++)
#define pr cout<<
#define en <<endl
#define sp <<' '
using namespace std;
typedef long long ll;

// int ar[200001];

int mind[2000000]; // mind[i] = min prime divisor of i.

vector<int> prm;
void build_sieve(int n) {
	mind[0] = mind[1] = 1;
	for (int i = 2; i <= n; ++i) {
		if (mind[i] == 0) {
			prm.push_back(i);
			mind[i] = i;
		}
		for (int j = 0; j < int(prm.size()) && prm[j] <= mind[i] && i * prm[j] <= n; ++j) {
			mind[i * prm[j]] = prm[j];
		}
	}
}


main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t,n ;
	build_sieve(200000);
	pr "Primes: ";fr(i,100) pr i<<" : "<<mind[i] en;
	cin>>t;
	while(t--)
	{
		cin>>n;
		
	}
}


