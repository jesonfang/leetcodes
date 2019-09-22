#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLUMN 500
#define ROWS 1000

char arr[ROWS][COLUMN] = {0};

char * convert(char * s, int numRows)
{
	char *res = NULL;

	if(s == NULL || numRows <= 0 || strlen(s) <= numRows || numRows <= 1)
		return s;

	int lenOfString = strlen(s);
	int row = 0, NextRow = 0, NextColum = 0;

	res = malloc(strlen(s) + 1);
	if(res == NULL)
		return NULL;

	memset(res, 0, strlen(s) + 1);
	memset(arr, 0, COLUMN * ROWS);

	//Total string iterations
	while(*s != '\0')
	{
		//printf("NextColum:%d\n", NextColum);
		//Arrary idx start with 0
		if(NextColum == 0 || NextColum > 0 && NextColum % (numRows - 1) == 0)
		{
			for(row = 0; row < numRows; row ++)
			{
				if(*s == '\0')
					break;
				
				arr[row][NextColum] = *s;
				s ++;
			}

			NextColum ++;
			NextRow = numRows - 2;//skip last one from bottom
		}
		else
		{			
			int i = NextRow;

			for(; i > 0; i --)
			{
				arr[NextRow][NextColum] = *s;
				
				s++;
				NextRow--;

				if(*s == '\0')
					break;

				NextColum ++;
			}
		}
	}
	
	int i,j;
	char *p = res;

	for(i = 0; i < numRows; i ++)
	{
		for(j = 0; j < COLUMN; j ++)
		{
			if (arr[i][j] != '\0')
			{
				*(p++) = arr[i][j];
			}
		}
	}

	return res;
}


int main(int argc, char const *argv[])
{
	char *s = "PAYPALISHIRING";
	//char *s = "AB";

	if (argc <= 1){
		printf("a.out xx\n");
		exit(1);
	}

	int row = atoi(argv[1]);

	char *res = convert(s, row);

	printf("res=[%s]\n", res);
	/* code */
	return 0;
}