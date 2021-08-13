#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define scani(n) scanf("%d",&n)
#define scanl(n) scanf("%lld",&n)
#define fr(i,n) for(int i=0;i<n;i++)
#define pr cout<<
#define en <<endl
#define sp <<' '
using namespace std;
typedef long long ll;

int ar[101]={1,2,3,4,5,6},sel[101],n=6,r=3;

//Generating combi to select r elements from n elem of ar.
void combi(int remain,int pos) // selecting remain items from ar[pos:]
{
	if(remain==0)
	{
		//a combi is ready.
		fr(i,r)
			pr sel[i] sp;
		pr endl;
	}
	else
	{
		for(int i=pos;i<=n-remain;i++)
		{
			sel[r-remain]=ar[i];
			combi(remain-1,i+1);
		}
	}
}

main()
{
	combi(r,0);
	
	
}







