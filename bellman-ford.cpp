#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<unordered_map>
#define umap unordered_map
#define pii pair<int,int>
#define F first
#define S second
#define inf 1000000007
#define fr(i,n) for(int i=0;i<n;i++)
#define pr cout<<
#define en <<endl
#define sp <<' '

using namespace std;
typedef long long ll;

int path[100001],N,M;
// umap<int,umap<int,int>> wt;  // when N>10000.
int wt[10001][10001]; 			// when N<10000. 
ll dis[100001];
vector<int> nbr[100001];

// needs- nbr, wt, dis, N, inf. Complexity - O(EV). Detect -ne cycle.
// N=no of vertices. inf=infinity value. ans is in dis(distance array). 
// max_weight*N<inf must be true. If any distance can go >inf make dis=ll,inf =10^18.

bool bellman(int root)
{
	for(int i=1;i<=N;i++)
		dis[i]=inf;
	dis[root]=0;
	
	int ind=0,nn=N,cnt,n1;
	while(nn--)
	{
		cnt=0;
		for(int n1=1;n1<=N;n1++)
		{
			auto w=dis[n1];
			auto& wtn1= wt[n1];
			for(int n2:nbr[n1])
			{
				if( w+wtn1[n2] < dis[n2] )
				{
					dis[n2]=w+wtn1[n2];
					path[n2]=n1;
					cnt++;
				}
			}
		}
		if(cnt==0) return 0;
		// pr "nn: ";for(int i=1;i<=N;i++) pr dis[i] sp; pr endl;
	}
	return 1; // Error, negetive weight cycle found.
}


main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,n1,n2,w;
	cin>>N>>M;
	
	fr(i,M)
	{
		cin>>n1>>n2 >>w;
		nbr[n1].push_back(n2);
		wt[n1][n2]=w;
		nbr[n2].push_back(n1);
		wt[n2][n1]=w;
	}
	//root =1
	if(bellman(1)) pr "-ve cycle found." en;
	
	for(int i=1;i<=N;i++) pr dis[i] sp; pr endl;
	for(int i=1;i<=N;i++) pr path[i] sp; pr endl;
	
	if(bellman(2)) pr "-ve cycle found." en;
	for(int i=1;i<=N;i++) pr dis[i] sp; pr endl;
	for(int i=1;i<=N;i++) pr path[i] sp; pr endl;
	
}
/*
6 9
1 2 9
1 3 20
1 4 5
2 3 8
3 6 6
3 5 4
3 4 5
4 5 12
6 5 1

0 9 10 5 14 15
0 1 4 1 3 5
*/






