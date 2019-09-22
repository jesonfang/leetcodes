#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



int reverse(int x)
{
    long int result = 0;
        
    if((x > (pow(2, 31) - 1)) || x < pow(-2, 31))
    	return 0;

    while (x != 0) {
        int digit = x % 10;

        //printf("result=%d\n", result);
        
        result *= 10;

        result += digit;
        
        x = x / 10;
    }

    if((result > (pow(2, 31) - 1)) || result < pow(-2, 31))
     	return 0;
    
    return result;
}

int main(int argc, char *argv[])
{
	int x=1534236469;
	printf("x=%d reverse=%d\n", x, reverse(x));
	return 0;
}

