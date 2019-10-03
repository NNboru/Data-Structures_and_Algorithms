#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#define pii pair<int,int>
#define F first
#define S second
#define fr(i,n) for(int i=0;i<n;++i)
#define pr cout<<
#define en <<'\n'
#define sp <<' '
using namespace std;
typedef long long ll;

int ar1[31][31]={{0,1,2},{1,2,3}},ar2[31][31]={{0},{1},{2}},res[31][31] ;

void multiply(int mat1[][31], int mat2[][31], int res[][31], int p, int q, int r)
{
    // res[p][r] = mat1[p][q] * mat2[q][r].
	for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < r; j++)
        {
            res[i][j] = 0;
            for (int k = 0; k < q; k++)
                res[i][j] += mat1[i][k] *mat2[k][j];
        }
    }
}

main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	multiply(ar1,ar2,res,2,3,1);
	fr(i,2)
	{
		fr(j,1) pr res[i][j] sp;
		pr endl;
	}
	
}


