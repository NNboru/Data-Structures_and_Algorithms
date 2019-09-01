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

int indar[100001],path[100001],N,M,nn;
// umap<int,umap<int,int>> wt;  // when N>10000.
int wt[10001][10001]; 			// when N<10000.
ll dis[100001];
pair<ll,int> heap[100001];
vector<int> nbr[100001];
bool chk[100001];

// needs- heap, indar, chk, nbr, wt, dis, path, N, nn, inf. Complexity - O( (E+V)log(V) )
// N=no of vertices. nn= present no of vertices in min-heap. inf=infinity value. ans is in dis(distance array). 
// max_weight*N<inf must be true. If any distance can go >inf make heap = pair<ll,int>,dis=ll,inf =10^18.
void Swap(int a,int b)
{
	swap(heap[a],heap[b]);
	indar[heap[a].second]=a;
	indar[heap[b].second]=b;
}
void godown(int nd)
{
	int big=nd,L,R;
	while(true)
	{
		L=nd<<1; R=L+1;
		if(L<=nn)
			if(heap[L].first<heap[big].first)
				big=L;
		if(R<=nn)
			if(heap[R].first<heap[big].first)
				big=R;
		if(big==nd)
			break;
		Swap(nd,big);
		nd=big;
	}
}
void goup(int nd)
{
	while(nd>1 and heap[nd>>1].first>heap[nd].first)
	{
		Swap(nd>>1,nd);
		nd>>=1;
	}
}
auto pop()
{
	auto val=heap[1];
	Swap(1,nn);
	if(nn==0) pr "Error" en;
	nn--;
	godown(1);
	return val;
}
void change(int nd, int val)
{
	heap[nd].first=val;
	goup(nd);
}

void dijkstra(int root)
{
	for(int i=1;i<=N;i++)
	{
		heap[i]={inf,i};
		indar[i]=i;
	}
	change(root,0);
	// fill_n(chk,N+1,0); // clear check.
	chk[root]=1;
	
	int ind=0;
	nn=N;
	while(nn>0)
	{
		auto nd=pop();
		auto w=nd.first;
		int v=nd.second;
		dis[v]=w;
		chk[v]=1;
		for(int ver:nbr[v])
		{
			if(chk[ver]==0)
			{
				if( w+wt[v][ver] < heap[indar[ver]].first )
				{
					change(indar[ver],w+wt[v][ver]);
					path[ver]=v;
				}
			}
		}
		// pr "nn: "<<nn en;for(int i=1;i<=nn; i++) pr heap[i].F sp<<heap[i].S en;
		// for(int i=1;i<=N;i++) pr indar[i] sp;pr endl;pr endl;
	}
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
	dijkstra(1);
	for(int i=1;i<=N;i++) pr dis[i] sp; pr endl;
	for(int i=1;i<=N;i++) pr path[i] sp; pr endl;
	
	// dijkstra(2);
	// for(int i=1;i<=N;i++) pr dis[i] sp; pr endl;
	// for(int i=1;i<=N;i++) pr path[i] sp; pr endl;
	
	
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





