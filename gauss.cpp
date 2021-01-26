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


// from cp-algorithms.
const double EPS = 1e-9;
const int INF = 2; // it doesn't actually have to be infinity or a big number

// return 1-unique, 0-no, 2-infinity solution. Converts a into an identity matrix.
int gauss(vector<vector<double>> &a , vector<double> &ans) {
    int n = (int) a.size();
    int m = (int) a[0].size() - 1;
	
    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        int sel = row;
        for (int i=row; i<n; ++i)
            if (abs (a[i][col]) > abs (a[sel][col]))
                sel = i;
        if (abs (a[sel][col]) < EPS)
            continue;
        for (int i=col; i<=m; ++i)
            swap (a[sel][i], a[row][i]);
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row) {
                double c = a[i][col] / a[row][col];
                for (int j=col; j<=m; ++j)
                    a[i][j] -= a[row][j] * c;
            }
        ++row;
    }

    ans.assign (m, 0);
    for (int i=0; i<m; ++i)
        if (where[i] != -1)
            ans[i] = a[where[i]][m] / a[where[i]][i];
    for (int i=0; i<n; ++i) {
        double sum = 0;
        for (int j=0; j<m; ++j)
            sum += ans[j] * a[i][j];
        if (abs (sum - a[i][m]) > EPS)
            return 0;
    }

    for (int i=0; i<m; ++i)
        if (where[i] == -1)
            return INF;
    return 1;
}


main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	vector<vector<double>> a = { { 2,1,10 }, {1,-1,2} };
	
	vector<double> ans;
	
	gauss( a , ans );
	
	pr "2x + y =10 " en<<
	   "x  - y = 2 " en<<
	   "x,y = " << ans[0] sp<<ans[1];
		
	
}
