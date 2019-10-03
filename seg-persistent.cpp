// Persistent tree data structure- collection of segment trees after each update.
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
#define N 10
using namespace std;
typedef long long ll;

int ar[100001];
struct node
{
	int l=0,r=0,val=0,cnt=0;
};
node ptrs[10000001];
int cnt=1,root[100001];

bool ch[200001];
void dfs(int root,int l,int r)
{
	if(ch[root]==0)
	{
		pr l sp<<r sp<<ptrs[root].cnt sp<<ptrs[root].val sp en;
		ch[root]=1;
	}
	if(ptrs[root].l!=0 and ch[ptrs[root].l]==0)
		dfs(ptrs[root].l,l,(l+r)/2);
	if(ptrs[root].r!=0 and ch[ptrs[root].r]==0)
		dfs(ptrs[root].r,(l+r)/2+1,r);
	
}
void dfs(int root)
{
	dfs(root,1,N);
	fr(i,cnt) ch[i]=0;
	pr endl;
}

int addseg(int oldr, int l, int r, int pos, int val)
{
	int newr=cnt++,nr=newr;
	ptrs[newr].val=ptrs[oldr].val+val;
	ptrs[newr].cnt=ptrs[oldr].cnt+1;
	
	int mid,left;
	while(l!=r)
	{
		mid=(l+r)/2;
		if(pos<=mid) left=1;
		else left=0;
		if(left)
			ptrs[newr].r=ptrs[oldr].r;
		else
			ptrs[newr].l=ptrs[oldr].l;
		if(left)
		{
			oldr=ptrs[oldr].l;
			ptrs[newr].l=cnt;
			r=mid;
		}
		else
		{
			oldr=ptrs[oldr].r;
			ptrs[newr].r=cnt;
			l=mid+1;
		}
		newr=cnt++;
		ptrs[newr].val=ptrs[oldr].val+val;
		ptrs[newr].cnt=ptrs[oldr].cnt+1;
	}
	return nr;
}

main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,m ;
	
	cin>>n ;
	for(int i=1;i<=n;i++)
		cin>>ar[i];
	
	// making persistent segment tree for ar.
	for(int i=1;i<=n;i++)
	{
		root[i] = addseg(root[i-1],1,N,ar[i],ar[i]);
	}
	dfs(root[n]);
	
}







