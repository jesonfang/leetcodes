int cmp(const void *a, const void *b){
    return (*((int*)a) > *((int*)b));
}

bool containsDuplicate(int* nums, int numsSize) {
    int i = 0;
    
    if (numsSize <= 0)
        return false;
        
    //sort firstly
    qsort(nums, numsSize, sizeof(int), cmp);
    
    for(i = 0; i < numsSize - 1; i ++)
    {
        if (*(nums + i) == *(nums + i + 1))
        {
            printf("found, i:%d, data:%d\n", i , nums[i]);
            return true;
        }
    }
    
    
    return false;
}
