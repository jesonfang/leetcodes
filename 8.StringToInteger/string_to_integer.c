#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int doAtoi(char *valid_str, int positive)
{
	int res = 0, base_out_bound = 0;
	long int convert_count = 0;
	unsigned char skip_head_zeros = 1;
	long int base = 1;

	int max_int = (pow(2, 31) - 1);
	int min_int = (pow(-2, 31));

	char *p = valid_str;
	char *p_end = p;


	while(1)
	{
		if((*p_end) != '\0' && isdigit(*p_end))
		{
			if(skip_head_zeros && (*p_end - '0' == 0))
			{
				p ++;//skip zero
			}
			else
			{
				skip_head_zeros = 0;
			}

			p_end ++;
		}
		else
		{
			break;
		}
	}
	
	* (p_end --) = '\0';

	if(strlen(p) <= 0)
		return 0;

	while(p_end!= NULL)
	{
		if(p == p_end)
		{
			convert_count += (*p_end - '0') * base;
			break;
		}

		convert_count += (*p_end - '0') * base;

		base *= 10;

		if(base >= max_int)
		{
			base_out_bound = 1;
			break;
		}

		p_end -= 1;//From end to start
	}

	if(!positive)
	{
		convert_count = 0 - convert_count;
	}

	if(positive && (base_out_bound || convert_count > max_int))
	{
		return max_int;
	}
	else if(!positive && (base_out_bound || convert_count < min_int))
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
	
	//strip space
	while(1)
	{
		if(*p == ' ')
			p ++;
		else
			break;
	}

	//strip non-valid convertion
    if(*p == '-')
    {
        res = doAtoi(++p, 0);
    }
    else if (*p == '+')
    {
        res = doAtoi(++p, 1);
    }
    else if(isdigit(*p))
    {
        res = doAtoi(p, 1);
    }
    else
    {
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