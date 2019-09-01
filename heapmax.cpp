#include<iostream>
#include<algorithm>
#include<cmath>
#define fr(i,n) for(int i=0;i<n;i++)
#define pr cout<<
#define en <<endl
#define sp <<' '
using namespace std;
typedef long long ll;

int heap[100001],N;

// Heap is heap. Total no of elements = N;
void godown(int* heap,int nd)
{
	int big=nd,L,R;
	while(true)
	{
		L=nd<<1; R=L+1;
		if(L<=N)
			if(heap[L]>heap[big])
				big=L;
		if(R<=N)
			if(heap[R]>heap[big])
				big=R;
		if(big==nd)
			break;
		swap(heap[nd],heap[big]);
		nd=big;
	}
}
void goup(int* heap,int nd)
{
	while(nd>1 and heap[nd>>1]<heap[nd])
	{
		swap(heap[nd>>1],heap[nd]);
		nd>>=1;
	}
}
void makeheap(int* heap)
{
	for(int i=N/2;i>0;i--)
		godown(heap,i);
}
void push(int* heap,int val)
{
	N++;
	heap[N]=val;
	goup(heap,N);
}
int pop(int* heap)
{
	int val=heap[1];
	heap[1]=heap[N];
	if(N==0) pr "Error" en;
	N--;
	godown(heap,1);
	return val;
}
void change(int* heap,int nd, int val)
{
	if(val>heap[nd])
	{
		heap[nd]=val;
		goup(heap,nd);
	}
	if(val<heap[nd])
	{
		heap[nd]=val;
		godown(heap,nd);
	}
}


main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,m,val ;
	
	cin>>N ;
	for(int i=1;i<=N;i++)
		cin>>heap[i];
	
	makeheap(heap);
	
	while(1)
	{
		for(int i=1;i<=N;i++)
			pr heap[i] sp;
		pr endl;
		cin>>m;
		if(m==1)
		{
			// push
			cin>>n;
			push(heap,n);
		}
		else if(m==2)
		{
			//pop
			pr pop(heap) en;
		}
		else
		{
			// change 
			cin>>n>>val;
			change(heap,n,val);
		}
	}
	
	
}







