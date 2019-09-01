/*
Segment tree using link-list. Tree size can go up to 10^18 but no of items <=10^6.
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#define fr(i,n) for(int i=1;i<=n;i++)
#define pr cout<<
#define en <<endl
#define sp <<' '
#define N 10
using namespace std;
typedef long long ll;

int ar[200001];
bool treeAdd=0;

struct node
{
	int l=0,r=0;// int p=0;
	int cnt=0;
};
node ptrs[10000001];
int cnt=1;

void add(int root,int l,int r,int pos)
{
	// root contains data for range l-r. To insert value=pos at position pos.
	
	// pr "adding - "<<l sp<<r sp<<pos en;
	if(l==r)
	{
		// ptrs[root].cnt++; 	 // if multiple items can exist.(multiset tree)
		if(ptrs[root].cnt==0) 	// if multiple items cannot exist. (set tree)
		{
			treeAdd=1;
			ptrs[root].cnt=1; 
		}
		return;
	}
	int mid=(l+r)/2;
	if(pos<=mid)
	{
		// go left.
		if(ptrs[root].l==0)
		{
			ptrs[root].l=cnt++;
			// ptrs[ptrs[root].l].p=root;//storing parent.
		}
		add(ptrs[root].l,l,mid,pos);
	}
	else
	{
		//go right.
		if(ptrs[root].r==0)
		{
			ptrs[root].r=cnt++;
			// ptrs[ptrs[root].r].p=root;//storing parent.
		}
		add(ptrs[root].r,mid+1,r,pos);
	}
	
	// ptrs[root].cnt++; 	 	// if multiple items can exist.
	ptrs[root].cnt+=treeAdd; // if multiple items cannot exist.
	
}

int queryEqual(int root, int l, int r, int pos)
{
	// return no of elements of ar with value=pos.
	int mid;
	while(l!=r)
	{
		mid=(l+r)/2;
		pr l sp<<r sp<<ptrs[root].cnt en;
		if(pos<=mid)
		{
			// go left.
			root=ptrs[root].l;
			if(root==0)
				return 0;
			r=mid;
		}
		else
		{
			//go right.
			root=ptrs[root].r;
			if(root==0)
				return 0;
			l=mid+1;
		}
	}
	return ptrs[root].cnt;
}

int querySmaller(int root, int l, int r, int pos)
{
	// return no of elements of ar with value<pos.
	int ans=0,mid;
	while(l!=r)
	{
		mid=(l+r)/2;
		if(pos<=mid)
		{
			// go left.
			root=ptrs[root].l;
			if(root==0)
				return ans;
			r=mid;
		}
		else
		{
			// go right.
			ans+=ptrs[ptrs[root].l].cnt;
			root=ptrs[root].r;
			if(root==0)
				return ans;
			l=mid+1;
		}
	}
	return ans; // for value<=pos return ans+ptrs[root].cnt;
}

int queryBigger(int root, int l, int r, int pos)
{
	// return no of elements of ar with value>pos.
	int ans=0,mid;
	while(l!=r)
	{
		mid=(l+r)/2;
		if(pos<=mid)
		{
			// go left.
			ans+=ptrs[ptrs[root].r].cnt;
			root=ptrs[root].l;
			if(root==0)
				return ans;
			r=mid;
		}
		else
		{
			// go right.
			root=ptrs[root].r;
			if(root==0)
				return ans;
			l=mid+1;
		}
	}
	return ans; // for value>=pos return ans+ptrs[root].cnt;
}

int biggest(int nd, int L, int R)
{
	// return max pos which has value under node nd having range - L to R. 
	if(ptrs[nd].cnt==0)
		return -1; // no value exist.
	int mid;
	while(L!=R)
	{
		mid=(L+R)/2;
		if(ptrs[ptrs[nd].r].cnt)
		{
			// go right.
			L=mid+1;
			nd=ptrs[nd].r;
		}
		else
		{
			// go left.
			R=mid;
			nd=ptrs[nd].l;
		}
	}
	return L;
}

int findleft(int root, int pos)
{
	// 
}

int smallest(int nd, int L, int R)
{
	// return min pos which has value under node nd having range - L to R. 
	if(ptrs[nd].cnt==0)
		return -1; // no value exist.
	int mid;
	while(L!=R)
	{
		mid=(L+R)/2;
		if(ptrs[ptrs[nd].l].cnt)
		{
			// go left.
			R=mid;
			nd=ptrs[nd].l;
		}
		else
		{
			// go right.
			L=mid+1;
			nd=ptrs[nd].r;
		}
	}
	return L;
}

bool ch[200001];
void dfs(int root,int l,int r)
{
	if(ch[root]==0)
	{
		pr l sp<<r sp<<ptrs[root].cnt en;
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

main()
{
	//ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,m ;
	
	cin>>n ;
	fr(i,n) cin>>ar[i];
	
	int root=cnt++;
	// ptrs[root].p=root;
	
	fr(i,n)
	{
		treeAdd=0;
		add(root,1,N,ar[i]);
		
	}
	dfs(root);
	
	// dfs(root);
	pr queryEqual(root,1,N,4) en;
	pr querySmaller(root,1,N,4) en;
	pr queryBigger(root,1,N,4) en;
	// pr queryEqual(root,1,N,4) en;
	
	
	
	
}







