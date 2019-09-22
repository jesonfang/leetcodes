void moveZeroes(int* nums, int numsSize) {
    int *p, *q;
    int i = 0;
    
    if (nums == NULL || numsSize <= 0){
        return ;
    }
    
    p = nums;
    q = p + 1;
    
    for(i = 0; i < numsSize - 1; i ++){
        if (*p == 0 && *q == 0)
        {
            q ++;
            continue;
        }
        
        if (*p == 0 && *q != 0){
            *p = *q;
            *q = 0;
        }
        
        p ++;
        q ++;
    }
}
