#define MAX(x,y) (x > y ? x : y)
int rob(int* nums, int numsSize) {

	int i = 0;
	
	if (nums == NULL || numsSize <= 0)
		return 0;
	
	int a = 0, b = 0;
		
	for(i = 0; i < numsSize; i ++)
	{
		if (i % 2 == 0) 
		{
			a += nums[i];
			a = MAX(a, b);
		}
		else
	    {
			b += nums[i];
			b = MAX(a, b);
		}
	}
	
	return MAX(a, b);	
}

