struct NumArray {
    int val;
    struct NumArray *next;
};

/** Initialize your data structure here. */
struct NumArray* NumArrayCreate(int* nums, int numsSize) {
	struct NumArray *head = NULL, *tmpNext = NULL;
	int i = 0;
	
	if(!nums || numsSize <= 0)
		return NULL;
	
	while(numsSize --)
	{
		struct NumArray *tmp = malloc(sizeof(struct NumArray));
		
		if(tmp == NULL){
			return NULL;			
		}	
		
		tmp->val = nums[i++];
		tmp->next = NULL;
		
		if(head == NULL)
		{
			head = tmp;
			tmpNext = head;
			continue;
		}
		else
		{
			tmpNext->next = tmp;
			tmpNext = tmp;
		}
	}	
	
	return head;    
}

int sumRange(struct NumArray* numArray, int i, int j) {
    if(NULL == numArray || i > j)
    {
    	return 0;
    }
    
    int dist = j - i + 1;
    int sum = 0;
    
    struct NumArray *p = numArray;
    
    while(i)
    {
  		if(p->next){
			p = p->next;		
		}
    
    	i --;
    }
    
    while(dist)
    {
    	if(p){
    		//printf("p->val=[%d]\n", p->val);
	    	sum += p->val;
	    	p = p->next;
	    }
    	else{
	    	break;
	    }
	    
	    dist -= 1;
    }
    
    return sum;
}

/** Deallocates memory previously allocated for the data structure. */
void NumArrayFree(struct NumArray* numArray) {
	struct NumArray*p = numArray;
    while(p)
    {
    	struct NumArray *tmp = p->next;
    	free(p);
    	p = tmp;
    }
}
// Your NumArray object will be instantiated and called as such:
// struct NumArray* numArray = NumArrayCreate(nums, numsSize);
// sumRange(numArray, 0, 1);
// sumRange(numArray, 1, 2);
// NumArrayFree(numArray);
