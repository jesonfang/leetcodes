#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int doAtoi(char *valid_str)
{
	int positive = 1, res = 0, outOfBound = 0;
	long int convert_count = 0;

	int max_int = (pow(2, 31) - 1);
	int min_int = (pow(-2, 31));

	char *p = valid_str;

	if(*p == '-')
	{
		positive = 0;
	}
	
	if(!isdigit(*p))
	{	
		p ++;
	}
	
	//printf("Convert %s into integer, %s number.\n", p, positive ? "positive" : "negative");

	//extract whole num string
	char *p_end = p;
	
	unsigned char skip_zero = 1;

	while(1)
	{
		//printf("%s:%d, char:%c\n", __func__, __LINE__, *p_end);
		if((*p_end) != '\0' && isdigit(*p_end))
		{
			if(skip_zero && (*p_end - '0' == 0))
			{
				p ++;//skip zero
			}
			else
			{
				skip_zero = 0;
			}

			p_end ++;
		}
		else
		{
			break;
		}
	}
	
	*p_end = '\0';

	//printf("Convert %s into integer, strlen(%d).\n", p, strlen(p));

	if(strlen(p) <= 0)
		return 0;

	p_end --;

	long int base = 1;

	while(p_end!= NULL && isdigit(*p_end))
	{
		if(p == p_end)
		{
			convert_count += (*p_end - '0') * base;
			break;
		}

		convert_count += (*p_end - '0') * base;
		//printf("convert_count %ld .\n", convert_count);

		base *= 10;

		if(base >= max_int){
			outOfBound = 1;
			break;
		}
		p_end -= 1;//From end to start
	}

	if(!positive)
	{
		convert_count = 0 - convert_count;
	}

	//printf("convert_count:%d maxInt:%d minInt:%d\n", convert_count, max_int, min_int);

	if(positive && (outOfBound || convert_count > max_int))
	{
		return max_int;
	}
	else if(!positive && (outOfBound || convert_count < min_int))
	{
		return min_int;
	}

	res = convert_count;

	return res;
}

int myAtoi(char * str){
	int res = 0;
	char *p = str;

	if (p == NULL)
		return 0;	
	
	//printf("%s:%d, Convert %s into integer.\n", __func__, __LINE__, p);

	//strip space
	while(1)
	{
		if(*p == ' ')
			p ++;
		else
			break;
	}

	//strip non-valid convertion
	if(*p == '+' || *p == '-' || isdigit(*p))
	{
		res = doAtoi(p);
	}
	else
	{
		//printf("not a valid string can be converted.\n");
		return 0;
	}

	return res;
}


int main(int argc, char const *argv[])
{
	char *s = argv[1];

	int res = myAtoi(s);

	printf("string:%s res=%d\n", s, res);

	/* code */
	return 0;
}