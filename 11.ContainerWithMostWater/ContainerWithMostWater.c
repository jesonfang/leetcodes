#include <stdio.h>

#define MAX(X,Y) (X > Y ? X : Y)
#define MIN(X,Y) (X > Y ? Y : X)

int maxArea(int* height, int heightSize)
{
	int maxArea = 0;
	int idx_left = 0, idx_right = heightSize - 1, distance = 0;
	
	while(idx_left < idx_right)
	{
		distance = idx_right - idx_left;
		
		maxArea = MAX(maxArea, (MIN(height[idx_left], height[idx_right]) * distance));
		
		if(height[idx_left] > height[idx_right])
		{
			idx_right --;
		}
		else
		{
			idx_left ++;
		}		
	}

	return maxArea;
}


int main()
{
	int arr[] = {1,8,6,2,5,4,8,3,7};
	
	printf("maxArea=%d\n", maxArea(arr, sizeof(arr)/sizeof(int)));
	
	return 0;
}
