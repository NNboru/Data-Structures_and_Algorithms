#include<iostream>
#define fr(i,n) for(int i=0;i<n;i++)
#define pr cout<<
#define en <<endl
#define sp <<' '
using namespace std;
typedef long long ll;

// Compute a table P[1,N][1,logN] where P[i][j] is the 2j-th ancestor of i.
// par = parent array, L[i] = Level of node i.
void process(int N, int par[N], int P[MAXN][LOGMAXN])
{
	int i, j;

	//we initialize every element in P with -1
	for (i = 1; i <= N; i++)
		for (j = 0; 1 << j <= N; j++)
			P[i][j] = -1; 

	//the first ancestor of every node i is par[i]
	for (i = 1; i <= N; i++)
		P[i][0] = par[i]; 

	//bottom up dynamic programing
	for (j = 1; 1 << j < N; j++)
		for (i = 1; i <= N; i++)
			if (P[i][j - 1] != -1)
				P[i][j] = P[P[i][j - 1]][j - 1];
}

int query(int N, int P[MAXN][LOGMAXN], int par[MAXN],int L[MAXN], int p, int q)
{
	int tmp, lg, i; 

	//if p is situated on a higher level than q then we swap them
	if (L[p] < L[q])
		tmp = p, p = q, q = tmp; 

	//we compute the value of [log(L[p)]
	for (lg = 1; 1 << lg <= L[p]; lg++);
		lg--; 

	//we find the ancestor of node p situated on the same level
	//with q using the values in P
	for (i = lg; i >= 0; i--)
		if (L[p] - (1 << i) >= L[q])
		p = P[p][i]; 

	if (p == q)
		return p; 

	//we compute LCA(p, q) using the values in P
	for (i = lg; i >= 0; i--)
		if (P[p][i] != -1 && P[p][i] != P[q][i])
			p = P[p][i], q = P[q][i]; 

	return par[p];
}



