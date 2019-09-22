/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int hammingWeight(uint32_t n) {  
    int count = 0;  
    while (n != 0) {  
        count++;  
        n &= (n - 1);  
    }  
    return count;  
}  

int* countBits(int num, int* returnSize) {
    if (num < 0){
        *returnSize = 0;
        return NULL; 
    }
    
    int i; 
    int *retArray = malloc(sizeof(int) * (num + 1));
    
    for(i = 0; i <= num; i ++)
    {
        retArray[i] = hammingWeight(i);
    }
    
    *returnSize = i;
    return retArray;
}

