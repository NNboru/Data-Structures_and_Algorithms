// #include<bits/stdc++.h>
#include<iostream>
#include<complex>
#include<algorithm>
#include<cmath>
#include<vector>
/*
#include<set>
#include<map>
#include<unordered_map>
#define umap unordered_map
#include<unordered_set>
#define uset unordered_set
*/
#define pii pair<int,int>
#define F first
#define S second
#define fr(i,n) for(int i=0;i<n;++i)
#define pr cout<<
#define en <<'\n'
#define sp <<' '
using namespace std;
typedef long long ll;

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}

vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

main()
{
	// ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t=1,n, carry=0 ;
	auto ans = multiply( {1,2,3,4,5} , {5,4,3,2,1} );
	for(auto i:ans)
	{
		i+=carry;
		pr i%10 sp;
		carry=i/10;
	}
	
	
}

