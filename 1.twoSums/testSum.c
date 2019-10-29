
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i = 0, j = 0, id1 = 0,id2 = 0, found = 0;
    int *retarr =NULL;

    for(i = 0; i < numsSize; i ++)
    {
        for (j = numsSize - 1; j > i; j --)
        {
            if (nums[i] + nums[j] == target){
                id1 = i;
                id2 = j;
                found = 1;
                
                goto out;
            }
        }
    }

out:
    if (found)
    {
        retarr = calloc(1,sizeof(int)*2);

        retarr[0] = id1;
        retarr[1] = id2;
        *returnSize = 2;
    }
    
    return retarr;
}

