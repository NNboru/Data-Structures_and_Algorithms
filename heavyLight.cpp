#include<iostream>
#define fr(i,n) for(int i=0;i<n;i++)
#define pr cout<<
#define en <<endl
#define sp <<' '
using namespace std;
typedef long long ll;

// Initially all entries of chainHead[] are set to -1.
// nbr and subsize not defined here.
int chainNo=0,chainHead[N],chainPos[N],chainInd[N],chainSize[N];
void hld(int cur)
{
    if(chainHead[chainNo] == -1) chainHead[chainNo]=cur;
    chainInd[cur] = chainNo;
    chainPos[cur] = chainSize[chainNo];
    chainSize[chainNo]++;

    int ind = -1,mai = -1;
    for(int i : nbr[cur])
	{
		if(subsize[i] > mai)
		{
            mai = subsize[ i ];
            ind = i;
        }
    }

    if(ind >= 0) hld( nbr[cur][ind] );

    for(int i : nbr[cur]) {
        if(i != ind) {
            chainNo++;
            hld(i);
        }
    }
}


