int removeDuplicates(int* nums, int numsSize) 
{
	int i = 0;
	int j = 0;
	
	for(j = 0; j < numsSize ; j ++){
		if (j + 1 < numsSize && nums[j] != nums[j + 1]){
			nums[i] = nums[j];
			i ++;			
		}
		else if(j + 1 == numsSize){
			nums[i] = nums[j];
			i ++;
		}
	}
	
	return i;	
}
