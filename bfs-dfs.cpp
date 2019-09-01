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

int ar[100001];
vector<int> nbr[100001];
bool chk[100001];

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

void dfs()
{
	//dfs - ( ar-temp, nbr, chk-marking visited. )
	ar[0]=1;
	chk[1]=1;
	int last=0;
	bool a;
	while(last>=0)
	{
		a=1;
		for(int i:nbr[ar[last]])
			if(chk[i]==0)
			{
				chk[i]=1;
				ar[++last]=i;
				//process node=i.
				a=0;
				break;
			}
		if(a)
			last--;//backtrack-delete last node.
	}
	
}

main()
{
		int n,n1,n2;
		nbr.clear();
		cin>>n;
		fr(i,n-1)
		{
			cin>>n1>>n2;
			nbr[n1].push_back(n2);
			nbr[n2].push_back(n1);
		}
		bfs();
		
		// pr "bfs: ";for(int i=0;i<n;i++) pr ar[i] sp;pr endl;//pppppppppppppppppppppppppp
		
}






