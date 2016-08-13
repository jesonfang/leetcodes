#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
        int i = 0, j = 0, id1 = 0,id2 = 0;
        int *retarr =NULL;
		
        for(i = 0; i < numsSize; i ++)
        {
            for (j = numsSize - 1; j > i; j --)
            {
                if (nums[i] + nums[j] == target){
                    id1 = i;
                    id2 = j;

                    goto out;
                }
            }
        }
        
out:
        retarr = malloc(sizeof(int)*2);
        
        *retarr = id1 ;
        *(retarr + 1) = id2 ;
        
        return retarr;
}



int main()
{
	int array[] = {3,2,4};
	
	int target = 6;
	
	
	int *retArr = twoSum(array, sizeof(array)/sizeof(int), target);
	
	if (retArr){
		printf("Input:[%d  %d  %d, target=[ %d ]]\n", array[0], array[1], array[2], target);
		printf("result:[%d  %d]\n", retArr[0], retArr[1]);
		free(retArr);
	}
	
	return 0;
}

