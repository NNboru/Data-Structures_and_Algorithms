// #include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cmath>
/*
#include<vector>
#include<set>
#include<map>
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

int ar[200001]{1,3,5,7,9,10,11};

// ar = array in which to search, n=no of items, val=value to search
int lowerBound(int ar[], int n, int val){
	int l=0, r=n-1, mid;
	while(l<=r){
		mid = (l+r)/2;
		if(ar[mid]==val){
			return mid;
		}
		else if(val<ar[mid]){
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	// no need to check mid-1
	// checking mid
	if(ar[mid]>val)
		return mid;
	// checking mid+1
	return mid+1;
}

// ar = array in which to search, n=no of items, val=value to search
int binarySearch(int ar[], int n, int val){
	int l=0, r=n-1, mid;
	while(l<=r){
		mid = (l+r)/2;
		if(ar[mid]==val){
			return mid;
		}
		else if(val<ar[mid]){
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	return -1; // elem not found
}

main()
{
	// ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t=1,n ;
	cin>>n;
	cout<< binarySearch(ar,6,n) <<endl;
	cout<<   lowerBound(ar,6,n) <<endl;
}







