// #include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cmath>
/*
#include<vector>
#include<set>
#include<map>
*/
#define pii pair<int,int>
#define F first
#define S second
#define fr(i,n) for(int i=0;i<n;++i)
#define pr cout<<
#define en <<'\n'
#define sp <<' '
using namespace std;
typedef long long ll;

int ar[200001]{1,2,3,4,5};

class Segtree{
	public:
	struct node{
		node *Lptr=NULL,*Rptr=NULL;
		ll val, lazy=0;
		int L,R;
		node(int l, int r, int v=0){
			L=l, R=r, val=v;
		}
	};
	node* HEAD = NULL;
	
	node* createTree(int l, int r){
		if(l==r){
			return new node(l,r,ar[l]);
		}
		int mid = (l+r)/2;
		node *Lptr = createTree(l, mid), *Rptr = createTree(mid+1, r);
		ll val = Lptr->val + Rptr->val;
		node* tmp = new node(l,r,val);
		tmp->Lptr = Lptr;
		tmp->Rptr = Rptr;
		return tmp;
	}
	
	Segtree(int first, int last){
		HEAD = createTree(first,last);
	}
	
	ll query(int l, int r=-1, node* ptr=NULL){
		if(r<0) r=l;
		if(ptr==NULL)
			ptr=HEAD;
		
		if(ptr->L==l and ptr->R==r)
			return ptr->val + (r-l+1)*(ptr->lazy);
		
		int mid = (ptr->L + ptr->R)/2;
		if(r<=mid)
			return query(l,r,ptr->Lptr) + (r-l+1)*(ptr->lazy);
		if(l>mid)
			return query(l,r,ptr->Rptr) + (r-l+1)*(ptr->lazy);
		return query(l,mid,ptr->Lptr) + query(mid+1,r,ptr->Rptr) + (r-l+1)*(ptr->lazy);
	}
	
	void update(int l, int r, ll val, node* ptr=NULL){
		if(ptr==NULL)
			ptr=HEAD;
		
		if(ptr->L==l and ptr->R==r){
			ptr->lazy+=val;
			return;
		}
		ptr->val += (r-l+1)*val;
		
		int mid = (ptr->L + ptr->R)/2;
		if(r<=mid)
			update(l,r,val,ptr->Lptr);
		else if(l>mid)
			update(l,r,val,ptr->Rptr);
		else{
			update(l,mid,val,ptr->Lptr);
			update(mid+1,r,val,ptr->Rptr);
		}
	}
	
	void show(node* ptr = NULL){
		if(ptr==NULL) ptr=HEAD;
		
		cout<< ptr->L sp<<ptr->R sp<< ptr->val en;
		int mid = (ptr->L+ptr->R)/2;
		if(ptr->Lptr) show(ptr->Lptr);
		if(ptr->Rptr) show(ptr->Rptr);
	}

};


main()
{
	// ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t=1,n=5 ;
	// cin>>t;
	while(t--)
	{
		Segtree tree = Segtree(0, n-1);
		
		pr "array : ";fr(i,n) pr ar[i] sp;pr "\n\n";
		
		pr "show L,R,val :" en;
		tree.show();
		
		pr "query(1)   : "<< tree.query(1) en;
		pr "query(1,4) : "<< tree.query(1,4) en;
		pr "query(0,4) : "<< tree.query(0,4) <<"\n\n";
		
		tree.update(1,4,-1); // add -1 from index 1 to 4.
		
		pr "query(1)   : "<< tree.query(1) en;
		pr "query(1,4) : "<< tree.query(1,4) en;
		pr "query(0,4) : "<< tree.query(0,4) en;
	}
}







