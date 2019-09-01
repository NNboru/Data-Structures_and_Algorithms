#include<iostream>
#define fr(i,n) for(int i=0;i<n;i++)
#define pr cout<<
#define en <<endl
#define sp <<' '
using namespace std;
typedef long long ll;


int modInv(int a, int m)
{
    int m0 = m;
    int y = 0, x = 1;
    while (a > 1)
    {
        // q is quotient
        int q = a / m,t = m;
        // m is remainder now, process same as Euclid's algo
        m = a % m, a = t;
        t = y;
        // Update y and x
        y = x - q * y;
        x = t;
    }
    if (x < 0)
       x += m0;
    return x;
}


int bez(int a,int m)
{
	//Returns Modular inverse of a%m such that (a*ans)%m=gcd(a,m).
	// a should not be -ve.
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



