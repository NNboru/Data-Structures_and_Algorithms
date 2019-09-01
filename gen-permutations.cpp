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

int ar[100001]={1,2,3,4},n=4;

void output(int n)
{
	for(int i=0;i<n;i++)
		pr ar[i] sp;
	pr endl;
}
int genper(int n)
{
	// Heap Algorithm.
	int c[n]={0};
	
	output(n);
	
	int i=0;
	while(i<n)
	{
		if(c[i]<i)
		{
			int temp=ar[i];
			if(i%2==0)
			{
				ar[i]=ar[0];
				ar[0]=temp;
			}
			else
			{
				ar[i]=ar[c[i]];
				ar[c[i]]=temp;
			}
			output(n);
			c[i]+=1;
			i=0;
		}
		else
		{
			c[i]=0;
			i++;
		}
	}
	

}
main()
{
	genper(n);// generate permutations for n elements of "ar". 
	
	
}







