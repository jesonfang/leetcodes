#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLUMN 100
#define ROWS 100

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

	char *p = res;

	//Total string iterations
	while(*s != '\0')
	{
		//printf("NextColum:%d\n", NextColum);
		//Arrary idx start with 0
		if(NextColum == 0 || NextColum > 0 && NextColum % (numRows - 1) == 0)
		{
			int tmpColum = NextColum;

			if(tmpColum == 0)
			{
				//first column
				for(row = 0; row < numRows; row ++)
				{
					if(*s == '\0')
						break;

					arr[tmpColum][NextColum] = *s;
					s ++;
					tmpColum ++;
					printf("%s:%d tmpColum:%d NextColum:%d [%c]\n", __func__, __LINE__, row, NextColum, arr[row][NextColum]);
				}
			}
			else
			{
				//non first column
				for(row = 0; row < numRows; row ++)
				{
					if(*s == '\0')
						break;
					
					arr[row][NextColum] = *s;
					s ++;
					printf("%s:%d tmpColum:%d NextColum:%d [%c]\n", __func__, __LINE__, row, NextColum, arr[row][NextColum]);
					tmpColum ++;
				}
			}

			NextColum ++;
			NextRow = numRows - 1;
		}
		else
		{			
			int i = numRows - 2;//skip last one from bottom

			for(; i > 0; i --)
			{
				int k = --NextRow;
				arr[k][NextColum] = *s;
				
				printf("%s:%d k:%d NextColum:%d [%c]\n", __func__, __LINE__, k, NextColum, arr[k][NextColum]);

				s++;

				if(*s == '\0')
					break;
				NextColum ++;
				if(NextColum > 0 && NextColum % (numRows - 1) == 0)
					break;
			}
		}
	}
	
	//dumparrary();

	int i,j;

	for(i = 0; i < ROWS; i ++)
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
	char *s = "ABCDE";
	//char *s = "AB";

	if (argc <= 1){
		printf("a.out xx\n");
		exit(1);
	}

	int row = atoi(argv[1]);

	printf("s=%s, len:%d, row:%d\n", s, strlen(s), row);

	char *res = convert(s, row);

	printf("res=[%s]\n", res);

	/* code */
	return 0;
}