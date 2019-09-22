// Forward declaration of isBadVersion API.
bool isBadVersion(int version);


int firstBadVersion(int n) {
    int left = 1, mid = 0, right = n;
	
	while(left < right)
	{
		mid = left+(right - left) / 2;	
		
		if(isBadVersion(mid))
		{
			//found one
			right = mid;
		}	
		else
		{
			left = mid + 1;	
		}
	}
	
	return left;
}
