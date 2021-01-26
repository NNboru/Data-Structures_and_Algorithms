/*
Segment tree using link-list. Tree size can go up to 10^18 but no of items <=10^6.
Have implementation for lazy and count but, count cannot be updated for a range.
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
	int l=0,r=0;// int p=0; // for parent.
	int cnt=0;
	int val,extra; // for sum range query.
};
node ptrs[10000001];
int cnt=1;

// for lazy operations-
void add(int nd,int L,int R, int l,int r,int val)
{
	// add val from l to r by lazy.
	if(l==L and r==R)
	{
		ptrs[nd].extra+=val;
		return;
	}
	ptrs[nd].val+=val*(r-l+1);
	int mid=(L+R)>>1;
	if(l<=mid)
		add(ptrs[nd].l,L,mid,l,min(r,mid),val);
	if(r>mid)
		add(ptrs[nd].r,mid+1,R,max(l,mid+1),r,val);
}
int query(int nd,int L,int R,int l,int r,int ex)
{
	// lazy query for range l to r.
	if(l==L and r==R)
		return ptrs[nd].val+ (ex+ptrs[nd].extra)*(R-L+1);
	int mid=(L+R)>>1;
	if(r<=mid)
		return query(ptrs[nd].l,L,mid,l,r,ex+ptrs[nd].extra);
	else if(l>mid)
		return query(ptrs[nd].r,mid+1,R,l,r,ex+ptrs[nd].extra);
	else
		return query(ptrs[nd].l,L,mid,l,mid,ex+ptrs[nd].extra) + query(ptrs[nd].r,mid+1,R,mid+1,r,ex+ptrs[nd].extra);
}

// for both adding val and count, but not for range. 
void add(int root,int l,int r,int pos,int val)
{
	// root contains data for range l-r. To increment cnt and insert val at position pos.
	ptrs[root].val+=val;
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
		add(ptrs[root].l,l,mid,pos,val);
	}
	else
	{
		//go right.
		if(ptrs[root].r==0)
		{
			ptrs[root].r=cnt++;
			// ptrs[ptrs[root].r].p=root;//storing parent.
		}
		add(ptrs[root].r,mid+1,r,pos,val);
	}
	
	// ptrs[root].cnt++; 	 	// if multiple items can exist.
	ptrs[root].cnt+=treeAdd; // if multiple items cannot exist.
	
}

// for count operations-
void add(int root,int l,int r,int pos)
{
	// root contains data for range l-r. To increment cnt at position pos.
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
	// return no of elements under root with value=pos.
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
	// return no of elements under root with value<pos.
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
	// return no of elements under root with value>pos.
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

int biggest(int nd, int l, int r)
{
	// return max pos which has value under node nd having range - l to r. 
	if(ptrs[nd].cnt==0)
		return -1; // no value exist.
	int mid;
	while(l!=r)
	{
		mid=(l+r)/2;
		if(ptrs[ptrs[nd].r].cnt)
		{
			// go right.
			l=mid+1;
			nd=ptrs[nd].r;
		}
		else
		{
			// go left.
			r=mid;
			nd=ptrs[nd].l;
		}
	}
	return l;
}
int smallest(int nd, int l, int r)
{
	// return min pos which has value under node nd having range - l to r. 
	if(ptrs[nd].cnt==0)
		return -1; // no value exist.
	int mid;
	while(l!=r)
	{
		mid=(l+r)/2;
		if(ptrs[ptrs[nd].l].cnt)
		{
			// go left.
			r=mid;
			nd=ptrs[nd].l;
		}
		else
		{
			// go right.
			l=mid+1;
			nd=ptrs[nd].r;
		}
	}
	return l;
}

int findleft(int nd, int l, int r, int pos)
{
	// to find largest element with index<=pos.
	int mid=(l+r)>>1;
	while(l!=r and (pos<=mid or ptrs[ptrs[nd].r].cnt==0))
	{
		nd=ptrs[nd].l;
		if(ptrs[nd].cnt==0)
			return -1;
		r=mid;
		mid=(l+r)>>1;
	}
	if(l==r)
	{
		if(ptrs[nd].cnt) return l;
		else return -1;
	}
	int val=findleft(ptrs[nd].r,mid+1,r,pos);
	if(val!=-1)
		return val;
	
	return biggest(ptrs[nd].l,l,mid);
}
int findright(int nd, int l, int r,int pos)
{
	// to find smallest element with index>=pos.
	int mid=(l+r)>>1;
	while(l!=r and (pos>mid or ptrs[ptrs[nd].l].cnt==0))
	{
		l=mid+1;
		nd=ptrs[nd].r;
		if(ptrs[nd].cnt==0)
			return -1;
		mid=(l+r)>>1;
	}
	if(l==r)
	{
		if(ptrs[nd].cnt) return l;
		else return -1;
	}
	int val=findright(ptrs[nd].l,l,mid,pos);
	if(val!=-1)
		return val;
	
	return smallest(ptrs[nd].r,mid+1,r);
}

bool ch[200001];
void dfs(int root,int l,int r)
{
	if(ch[root]==0)
	{
		pr l sp<<r sp<<ptrs[root].cnt sp<<ptrs[root].val sp<<ptrs[root].extra en;
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
	
	// fr(i,n)//for count.
	// {
		// treeAdd=0;
		// add(root,1,N,ar[i]);
	// }
	
	for(int i=1;i<=n;i++)// for range query.
	{
		treeAdd=0;
		add(root,1,N,i,ar[i]);
	}
	dfs(root);
	
	// dfs(root);
	// pr queryEqual(root,1,N,4) en;
	// pr querySmaller(root,1,N,4) en;
	// pr queryBigger(root,1,N,4) en;
	// pr queryEqual(root,1,N,4) en;
	// for(int i=1;i<=N;i++) pr findright(root,1,N,i) sp;
	
	pr query(root,1,N,3,8,0) en;
	add(root,1,N,3,4,5);
	dfs(root);
	pr query(root,1,N,3,8,0);
}







