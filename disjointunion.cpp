#include<iostream>
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

int tsize[100001],treeind[100001],N,M;
vector<int> nbr[100001],tree[100001];

// needs tree(stores vertices in tree[i]), tsize(size of tree[i]), treeind[i](tree to which ith vertex belong).
bool merge(int n1, int n2)
{
	// merges tree of vertex n1 with tree of vertex n2.
	if(treeind[n1]!=treeind[n2])
	{
		int tr1=treeind[n1];
		int tr2=treeind[n2];
		if(tsize[tr1]<tsize[tr2])
			swap(tr1,tr2);
		
		// merge tr2 with tr1.
		for(int i:tree[tr2])
			treeind[i]=tr1;
		tsize[tr1]+=tsize[tr2];
		tsize[tr2]=0;
		tree[tr1].insert(tree[tr1].end(),tree[tr2].begin(),tree[tr2].end());
		return 1;
	}
	return 0; // no merging is performed.
}


main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n1,n2 ;
	
	cin>>N>>M ;
	fr(i,M)
	{
		cin>>n1>>n2;
		nbr[n1].push_back(n2);
		nbr[n2].push_back(n1);
		
	}
	
	// initialize- N trees, ith tree with ith vertex only.
	for(int i=1;i<=N;i++)
	{
		tree[i]={i};
		treeind[i]=i;
		tsize[i]=1;
	}
	
	
}







