#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<unordered_map>
#define umap unordered_map
#include<unordered_set>
#define uset unordered_set
#define fr(i,n) for(int i=0;i<n;i++)
#define pr cout<<
#define en <<endl
#define sp <<' '
using namespace std;
typedef long long ll;

int ar[100001];// order[100001],tin[100001],tout[100001],time=1;
vector<int> nbr[100001];
bool chk[100001];
int ind =0;
// ar, chk, nbr.
void bfs()
{
	//bfs with root=1. Bfs traversal stored in ar. chk used to mark visited vertices. d=depth.
	int root=1;
	ar[0]=root;
	chk[root]=1;
	int ind=0,last=1,d=1,dind=1;
	while(ind!=last)
	{
		for(int i:nbr[ar[ind]])
			if(chk[i]==0)
			{
				chk[i]=1;
				ar[last++]=i;
			}
		ind++;
		if(ind==dind)
		{
			d++;
			dind=last;
		}
	}
	while(last--)
		chk[ar[last]]=0;
	
}

dfs(int root=1)
{
	// static int ind=0;
	// order[ind++]=root;
	chk[root]=1;
	ar[ind++]=root;
	//tin[root]=time++;
	for(int nd:nbr[root])
		if(chk[nd]==0)
		{
			// par[nd]=root;
			dfs(nd);
		}
	tout[root]=time++;
	
}

void dfs2()
{
	int ind=-1,ind2=0,pos=0,ver;
	int root=1;
	ar[++ind]=root;
	while(ind>=0)
	{
		ver=ar[ind--];
		if(chk[ver]==0)
		{
			chk[ver]=1;
			// order[ind2++]=ver;
		}
		for(auto i=nbr[ver].rbegin();i<nbr[ver].rend();++i)
			if(chk[*i]==0)
			{
				ar[++ind]=*i;
				// par[*i]=ver;
			}
	}
}

main()
{
		int n,n1,n2;
		cin>>n;
		fr(i,n-1)
		{
			cin>>n1>>n2;
			nbr[n1].push_back(n2);
			nbr[n2].push_back(n1);
		}
		dfs();
		fr(i,n) pr order[i] sp;
		// pr "bfs: ";for(int i=0;i<n;i++) pr ar[i] sp;pr endl;//pppppppppppppppppppppppppp
		
		
		fr(int i=1;i<=n;++i) nbr[i].clear();
}

/*
6
1 2
1 3
2 4
2 5
5 6

*/




