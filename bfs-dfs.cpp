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

int ar[200001], ind;// depth[200001],order[200001],tin[200001],tout[200001],time=1;
vector<int> nbr[200001];
bool vis[200001];

// ar, vis, nbr required.
// bfs with root=1. Bfs traversal stored in ar. vis used to mark visited vertices. d=depth.
void bfs(int root=1){
	if(vis[root]) return;
	vis[root]=1;
	ar[ind]=root;
	// depth[root]=0;
	int last=ind+1, d=1, dind=last;
	while(ind!=last){
		for(auto i:nbr[ar[ind]]){
			if(not vis[i]){
				vis[i]=1;
				ar[last++]=i;
				// depth[i]=d;
			}
		}
		ind++;
		// checking depth
		if(ind==dind){
			d++;
			dind=last;
		}
	}
}
void dfs(int root=1){
	if(vis[root]) return;
	// tin[root]=time++;
	vis[root]=1;
	ar[ind++] = root; // storing traversal
	for(auto i: nbr[root]){
		if(not vis[i]){
			// par[i] = root;
			dfs(i);
		}
	}
	// tout[root]=time++;
}

main()
{
		int n,m,n1,n2;
		cin>>n>>m;
		for(int i=0;i<m;++i)
		{
			cin>>n1>>n2;
			nbr[n1].push_back(n2);
			nbr[n2].push_back(n1);
		}
		
		// dfs
		ind=0;
		fr(i,n) dfs(i+1);
		pr "dfs: ";for(int i=0;i<ind;i++) pr ar[i] sp;pr endl;//pppppppppppppppppppppppppp
		
		// clearing visited array.
		for(int i=0;i<=n;i++) vis[i]=0;
		
		// bfs
		ind=0;
		fr(i,n) bfs(i+1);
		pr "bfs: ";for(int i=0;i<ind;i++) pr ar[i] sp;pr endl;//pppppppppppppppppppppppppp
		
		
		// for(int i=1;i<=n;++i) nbr[i].clear();
}


void dfs2(int root = 1)
{
	int ind=-1,ind2=0,pos=0,ver;
	ar[++ind]=root;
	while(ind>=0)
	{
		ver=ar[ind--];
		if(vis[ver]==0)
		{
			vis[ver]=1;
			// order[ind2++]=ver;
		}
		for(auto i=nbr[ver].rbegin();i<nbr[ver].rend();++i)
			if(vis[*i]==0)
			{
				ar[++ind]=*i;
				// par[*i]=ver;
			}
	}
}

/*
6 6
1 2
2 3
3 4
4 1
5 6
1 3

*/




