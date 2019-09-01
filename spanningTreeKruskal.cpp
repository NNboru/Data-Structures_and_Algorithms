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

// taking N<100001
int tsize[100001],treeind[100001],N;
vector<int> nbr[100001],tree[100001];
vector<pair<int,pii>> wtlist;

// needs- N, wtlist or nbr, tree, treeind, tsize. Complexity - O(E + V*log(V)).
vector<pii> spanningTree()
{
	for(int i=1;i<=N;i++)// clear
	{
		tree[i]={i};
		treeind[i]=i;
		tsize[i]=1;
	}
	
	vector<pii> ans; // edges of final spanning tree.
	int n1,n2,tr1,tr2;
	/*
	when we have to find any spanning tree - use nbr instead of wtlist. replace -
	for(int n1=1;n1<=N;n1++)
	{
		for(int n2:nbr[n1])
			if(treeind[n1]!=treeind[n2]) ...
	*/
	for(auto p:wtlist)
	{
		n1=p.second.first;
		n2=p.second.second;
		if(treeind[n1]!=treeind[n2])
		{
			ans.push_back({n1,n2});// ans+=p.first; //for min wt
			tr1=treeind[n1];
			tr2=treeind[n2];
			if(tsize[tr1]<tsize[tr2])
				swap(tr1,tr2);
			
			// merge tr2 with tr1.
			for(int i:tree[tr2])
				treeind[i]=tr1;
			tsize[tr1]+=tsize[tr2];
			tree[tr1].insert(tree[tr1].end(),tree[tr2].begin(),tree[tr2].end());
		}
	}
	return ans;
}

main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int M,n1,n2,w ;
	
	cin>>N>>M ;
	fr(i,M)
	{
		cin>>n1>>n2 >>w;
		nbr[n1].push_back(n2);
		nbr[n2].push_back(n1); // for spanning tree this line not needed.
		
		wtlist.push_back({w,{n1,n2}});
	}
	
	sort(wtlist.begin(),wtlist.end());
	
	auto ans= spanningTree();
	
	pr "ans: "<<ans.size() en;for(pii p:ans) pr p.first sp<<p.second en;
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

ans: 5
6 5
3 5
1 4
3 4
2 3
*/






