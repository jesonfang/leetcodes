/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
     int *retArray = NULL;
    
	if(numbers == NULL || numbersSize <= 0){
    	*returnSize = 0;
    	return NULL;
    }
    
    int i, j, tmp;
    
    i = 0;
    j = numbersSize - 1;
    
    while(i < j){
    	tmp = numbers[i] + numbers[j];
    	
    	if(tmp < target){
	    	i ++;
	    }
	    else if(tmp > target){
    		j --;	
    	}
    	else{
	    	goto out;	
	    }
    }
    
out:   
 
    retArray = malloc(sizeof(int) * 2);
    if(retArray == NULL){
    	*returnSize = 0;
    	return NULL;	
    }

	retArray[0] = i + 1;
	retArray[1] = j + 1;
	*returnSize = 2;
	
	return retArray;   
    
}
