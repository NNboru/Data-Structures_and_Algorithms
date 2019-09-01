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

int table[100001],posar[100001];

void gentable(int tab[],string& word)
{
	int pos=1,cnd=0;
	tab[0]=-1;
	
	while(pos<word.size())
	{
		if(word[pos]==word[cnd])
			tab[pos]=tab[cnd];
		else
		{
			tab[pos]=cnd;
			while(cnd>=0 and word[pos]!=word[cnd])
				cnd=tab[cnd];
		}
		pos++;
		cnd++;
	}
	tab[pos]=cnd;
	
}

int kmp(string &s,string &w)
{
	int j=0,k=0,np=0,wlen=w.size();
	gentable(table,w);
	
	while(j<s.size())
	{
		if(w[k]==s[j])
		{
			j++,k++;
			if(k==wlen)
			{
				posar[np++]=j-k;
				k=table[k];
			}
		}
		else
		{
			k=table[k];
			if(k<0)
			{
				j++,k++;
			}
		}
	}
	return np;
}


main()
{
	string s,w;
	int np;
	while(1)
	{
		cin>>s>>w;
		np=kmp(s,w);
		// fr(i,w.size()+1)pr table[i] sp;pr endl;
		
		fr(i,np)
			pr posar[i] sp;
		pr "np:"<<np<<endl;
		
		
		
		
	}
}







