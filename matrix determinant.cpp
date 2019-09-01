#include<iostream>
#include<algorithm>
#include<cmath>
#define fr(i,n) for(int i=0;i<n;i++)
#define pr cout<<
#define en <<endl
#define sp <<' '
#define MOD 998244353
using namespace std;
typedef long long ll;

ll mat[30][30],adj[31][31],N;

int bez(int a,int m)
{
	//Returns Modular inverse of a%m such that (a*ans)%m=gcd(a,m).
	// a should not be -ve, becoz mod return -ve.
	int siz=0,qar[10000],mc=m,q,r;
	q=a/m;
	r=a%m;
	while(r!=0)
	{
		qar[siz++]=q;
		a=m;
		m=r;
		q=a/m;
		r=a%m;
	}
	qar[siz++]=1;
	for(int i=siz-3;i>=0;i--)
		qar[i]=qar[i]*qar[i+1]+qar[i+2];
	if(siz%2) return mc-qar[1];
	return qar[1];
}

int determinantOfMatrix(ll mat[30][30],int n)   
{   
    ll num1,num2,det = 1,index,total = 1;   
	
    for(int i = 0; i < n; i++)
	{
		for(int j = i+1; j < n; j++)
		{
			num1 = mat[i][i];
			num2 = mat[j][i];
			for(int k = i; k < n; k++)
			{
				mat[j][k] = ((num1 * mat[j][k]) - (num2 * mat[i][k]))%MOD;
			}
			total = (total * num1)%MOD;
		}
	}  
    for(int i = 0; i < n; i++)
    {   
        det =( det * mat[i][i])%MOD;
    }
	// pr det sp<<total sp<<bez(total,MOD) en;
	if(total<0)
	{
		total=-total;
		det=-det;
	}
    return (det*bez(total,MOD))%MOD;
}

main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin>>n;
	fr(i,n)fr(j,n)
		cin>>mat[i][j];
	
	pr determinantOfMatrix(mat,n);
	
	
}


