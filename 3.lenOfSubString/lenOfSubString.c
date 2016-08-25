#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLongestSubstring(char* s)
{
    int lenOfString = strlen(s);
    int i = 0, max = 0, end = 0;
    
    if (lenOfString == 0)
    {
        return 0;
    }
    else if (lenOfString == 1)
    {
        return 1;
    }
    
    int location[256] , index = -1;;                  
    memset(location, 0xff, sizeof(location)); 

    for (i = 0; i < lenOfString; i ++)
    {
        if (location[s[i]] > index) 
        {                          
            index = location[s[i]];
        }                    

        if (i - index > max) 
        {      
            max = i - index;                     
        }  

        location[s[i]] = i; 
    }

    return max ;
}


int main()
{
    char *s = "abcabcbb";

    int lenOfsubstring = lengthOfLongestSubstring(s);

    printf("lenOfsubstring=[%d]\n", lenOfsubstring);
    
    return 0;
}




