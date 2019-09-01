#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<unordered_map>
#define umap unordered_map
#define scani(n) scanf("%d",&n)
#define scanl(n) scanf("%lld",&n)
#define fr(i,n) for(int i=1;i<=n;i++)
#define pr cout<<
#define en <<endl
#define sp <<' '
#define MOD 1000000021
using namespace std;
typedef long long ll;

int nbrind[100001],stack[100001],stack2[100001],disc[100001],low[100001];
umap<int,vector<int>> nbr;
vector<vector<int>> compo;
bool chk[100001],chk2[100001];

main()
{
	int t,N,M,K,v,v1,v2,ind,ind2,time,ver ;
	scani(t);
	while(t--)
	{
		scani(N); scani(M);
		fr(i,M)
		{
			scani(v1); scani(v2);
			nbr[v1].push_back(v2);
		}
		
		fr(i,N)
		{
			if(chk[i])
				continue;
			v=i;
			time=1;
			chk[v]=1;
			stack[0]=stack2[0]=v;
			ind=0;ind2=1;
			disc[v]=low[v]=1;
			while(true)
			{
				while(nbrind[v]<nbr[v].size())
				{
					ver=nbr[v][nbrind[v]++];
					if(chk[ver])
					{
						if(not chk2[ver])
							low[v]=min(low[v],disc[ver]);
					}
					else
					{
						v=ver;
						chk[v]=1;
						time++;
						disc[v]=time;
						low[v]=time;
						stack[++ind]=v;
						stack2[ind2++]=v;
					}
				}
				if(disc[v]==low[v])
				{
					vector<int> vec;
					ind2--;
					while(stack2[ind2]!=v)
					{
						chk2[stack2[ind2]]=1;
						vec.push_back(stack2[ind2--]);
					}
					vec.push_back(v);
					chk2[v]=1;
					compo.emplace_back(vec);
				}
				ind--;
				if(ind>=0)
				{
					low[stack[ind]]=min(low[stack[ind]],low[v]);
					v=stack[ind];
				}
				else break;
			}	
		}
		pr "compo: "<<compo.size() en;
		for(auto& vec :compo) {for(int i:vec) pr i sp;pr endl;}pr endl;
		
		
	}
	
}







