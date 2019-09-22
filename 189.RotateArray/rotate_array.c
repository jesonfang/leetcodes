
void rev(int [] num, int beg, int end) {
	while(beg < end) {
	    int tmp = num[beg];
	    num[beg] = num[end];
	    num[end] = tmp;
	    
	    beg ++;
	    end --;
	}    
}
    
void rotate(int[] nums, int k) {
	k = k % nums.length;
	if(k <= 0) {
	    return;
	}
	rev(nums, 0, nums.length-k-1);
	rev(nums, nums.length-k, nums.length-1);

	rev(nums, 0, nums.length-1);

}

