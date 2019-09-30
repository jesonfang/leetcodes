#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

typedef unsigned char  bool;

#define true 1
#define false 0

#define REG_EXP_MATCH_SINGLE_CHAR '.'
#define REG_EXP_MATCH_PRECED_CHAR '*'

bool isAlphAndLower(char x)
{
    if(isalpha(x) && islower(x))
    {
        return true;
    }

    return false;
}


bool isValidString(char *s)
{
    bool ret = true;
    char *p = s;

    if(!s)
        return false;

    if (s)
    {
        while(*p != '\0')
        {
            if(isAlphAndLower(*p))
            {
                p ++;
                continue;
            }
            else
            {
                ret = false;
                break;
            }
        }
    }

    return ret;   
}


bool isValidRegExpressString(char *s)
{
    bool ret = true;
    char *p = s;

    if(!s)
        return false;

    if (s)
    {
        while(*p != '\0')
        {
            if(isAlphAndLower(*p) || REG_EXP_MATCH_SINGLE_CHAR == *p || REG_EXP_MATCH_PRECED_CHAR == *p)
            {
                p ++;
                continue;
            }
            else
            {
                ret = false;
                break;
            }
        }
    }

    return ret;
}

bool doMatch(char *s, char *p)
{
    bool ret = false;

    return ret;
}

bool isMatch(char * s, char * p){
    bool ret = false;

    if(!s || !p)
        return ret;

    //check string validation
    if (isValidString(s) && isValidRegExpressString(p))
    {
        printf("valid string, Lets match..\n");
        ret = doMatch(s, p);
    }
    else
    {
        printf("We only support be empty and contains only lowercase letters a-z, and characters like . or *\n");
    }

    return ret;
}


int main(int argc, char const *argv[])
{
    
    printf("isMatch=%d\n", isMatch(argv[1], argv[2]));

    /* code */
    return 0;
}

