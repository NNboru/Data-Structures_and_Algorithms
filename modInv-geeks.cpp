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
    int y = 0, x = 1, t;
    while (a > 1)
    {
        // Update y and x
        t = y;
        y = x - (a/m0) * y;
        x = t;
        t = m0;
        // m is remainder now, process same as Euclid's algo
        m0 = a % m0;
		a = t;
    }
    if (x < 0)
       x += m;
    return x;
}

main()
{
	int m=11;
	for(int i=1;i<m;i++)
		pr modInv(i,m) sp;
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



