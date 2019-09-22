bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    if(!nums || numsSize <= 0)
    {
    	return false;
    }
    
    int Max_distance = 0;
    
    int i, j;
    
    for(i = 0; i < numsSize; i ++){
    	for(j = i + 1; j < numsSize; j ++){
	    	if(nums[i] == nums[j] && (j - i) <= k){
	    		Max_distance = (j - i);
	    		printf("Max dis:%d\n", Max_distance);
	    		return true;
	    	}
	    }
    }
    
    return false;
}
