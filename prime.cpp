#include<iostream>
#define pr cout<<
#define en <<endl
#define sp <<' '
#include<cmath>

using namespace std;

main()
{
	int i,j,k,n,np=3;
	cout<<"enter no : ";
	cin>>n;
	int prm[n+1]; prm[0]=2; prm[1]=3; prm[2]=5;
	int sq=3,s=9,inc=4;	
	for(i=7;i<n;i+=inc,inc=6-inc)
	{
		if (i>s)
		{
			sq++;
			s=round(pow(sq,2));
		}
		k=0;
		for(j=0;j<np;j++)
		{
			if (prm[j]>sq) break;
			if(i%prm[j]==0)
			{
				k=1;
				break;
			}
		}
		if (k==0) prm[np++]=i;
	}	
	for(i=0;i<np;i++) pr prm[i] sp;pr endl;
}