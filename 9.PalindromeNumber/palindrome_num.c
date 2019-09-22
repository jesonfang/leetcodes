#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

typedef unsigned char  bool;

#define true 1
#define false 0

char numString[32];

bool isPalindrome(int x){
	bool ret = true;

	if((x) < 10 && x > 0)
		return true;

	if(x < 0)
		return false;

	memset(numString, 0, sizeof(numString));
	snprintf(numString, sizeof(numString), "%d", x);

    int len = strlen(numString);
    int left = 0, right = len - 1;

    while(left <= right)
    {
        //printf("left:%c right:%c\n", str[left], str[right]);
        if(numString[left] == numString[right])
        {
            left ++;
            right --;
        }
        else
        {
            return false;
        }
    }

	return ret;
}


int main(int argc, char const *argv[])
{
	int x = atoi(argv[1]);
	printf("isPalindrome=%d\n", isPalindrome(x));

	/* code */
	return 0;
}

