// if element(k) is not found, it returns the index where k should be inserted.
ll bisearch(int fi,int la,int k)
{
	int ind,lac=la;
	while(fi!=la)
	{
		ind=(la+fi)>>1;
		if(k>ar[ind])
			fi=ind+1;
		else
			la=ind;
	}
	if(fi==lac and ar[fi]<k)
			return fi+1;
	return fi;
}
