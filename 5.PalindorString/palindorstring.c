#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define false 0
#define true 1

typedef unsigned char bool;

unsigned char dp[1000][1000] = {0};
bool isPalindromeString(const char *str);

char *longestPalindrome_dp(char *s)
{
    int start = 0, end = 0, len = 0, maxLen = 0;

    if((s == NULL) || !strcmp(s,"") || strlen(s) <= 1)
    {
        printf("return s [%s] len:%d\n", s, len);
        return s;
    }

    len = strlen(s);

    memset(dp, 0, 1000*1000*sizeof(unsigned char));

    char *tmp_string = malloc(len + 1);
    if(tmp_string == NULL)
        return NULL;

    for(start = len - 1; start >= 0; start --)
    {
        for(end = start ; end < len; end ++)
        {
            //printf("start:%d %c end:%d %c\n", start, s[start], end, s[end]);

            if (s[start] == s[end] && (end - start <= 2 || dp[start + 1][end - 1]))
            {
                dp[start][end] = true;

                if(end + 1 - start > maxLen)
                {
                    maxLen = end + 1 - start;

                    memset(tmp_string, 0, len + 1);
                    strncpy(tmp_string, s + start, maxLen);

                    //printf("palstring=(%s), start:%d end:%d\n", tmp_string, start, end);
                }
            }
        }
    }

end:

    return tmp_string;
}

bool isPalindromeString(const char *str)
{
    if (str == NULL || strlen(str) <= 0)
        return false;

    int len = strlen(str), i = 0;
    int left = 0, right = len - 1;

    while(left <= right)
    {
        //printf("left:%c right:%c\n", str[left], str[right]);
        if(str[left] == str[right])
        {
            left ++;
            right --;
        }
        else
        {
            return false;
        }
    }

    return true;
}

char * longestPalindrome(char * s)
{
    char *p = NULL, *ret_string = NULL;
    int len = strlen(s);
    int maxLen = 0;
    char *tmp_string = NULL;

    //printf("s [%s] len:%d\n", s, len);

    if((s == NULL) || !strcmp(s,"") || isPalindromeString(s) && len == strlen(s))
    {
        printf("return s [%s] len:%d\n", s, len);
        return s;
    }

    int i = 0;
    p = s;
    
    tmp_string = malloc(len + 1);
    if(tmp_string == NULL)
        return NULL;

    memset(tmp_string, 0, len + 1);

    for (i = 0; i < len; i ++)
    {
        //Find substring
        memset(tmp_string, 0, len + 1);
        strncpy(tmp_string, p, len - i);
        //printf("tmp_string [%s] i:%d isPalindrome [%d]\n", tmp_string, i, isPalindromeString(tmp_string));
        
        if(maxLen >= (s + len - p)){
            //printf("(s + len - p):%ld, maxLen:%d\n", (s + len - p), maxLen);
            break;
        }

        if (isPalindromeString(tmp_string) && strlen(tmp_string) > maxLen){
            maxLen = strlen(tmp_string);
            ret_string = strdup(tmp_string);               
        }

        if (i >= (len - 1) && *p != ('\0'))
        {
            //printf("reset loop\n");
            p ++;
            i = 0;
        }
    }

    printf("ret_string:%s, len:%d\n", ret_string, maxLen);

    return ret_string;
}



int main()
{
    //char *s = "ccd";
    char *s = "abcda";
    //char *s = "abccbcbb";
    //char *s = "a";
    //char *s = "gphyvqruxjmwhonjjrgumxjhfyupajxbjgthzdvrdqmdouuukeaxhjumkmmhdglqrrohydrmbvtuwstgkobyzjjtdtjroqpyusfsbjlusekghtfbdctvgmqzeybnwzlhdnhwzptgkzmujfldoiejmvxnorvbiubfflygrkedyirienybosqzrkbpcfidvkkafftgzwrcitqizelhfsruwmtrgaocjcyxdkovtdennrkmxwpdsxpxuarhgusizmwakrmhdwcgvfljhzcskclgrvvbrkesojyhofwqiwhiupujmkcvlywjtmbncurxxmpdskupyvvweuhbsnanzfioirecfxvmgcpwrpmbhmkdtckhvbxnsbcifhqwjjczfokovpqyjmbywtpaqcfjowxnmtirdsfeujyogbzjnjcmqyzciwjqxxgrxblvqbutqittroqadqlsdzihngpfpjovbkpeveidjpfjktavvwurqrgqdomiibfgqxwybcyovysydxyyymmiuwovnevzsjisdwgkcbsookbarezbhnwyqthcvzyodbcwjptvigcphawzxouixhbpezzirbhvomqhxkfdbokblqmrhhioyqubpyqhjrnwhjxsrodtblqxkhezubprqftrqcyrzwywqrgockioqdmzuqjkpmsyohtlcnesbgzqhkalwixfcgyeqdzhnnlzawrdgskurcxfbekbspupbduxqxjeczpmdvssikbivjhinaopbabrmvscthvoqqbkgekcgyrelxkwoawpbrcbszelnxlyikbulgmlwyffurimlfxurjsbzgddxbgqpcdsuutfiivjbyqzhprdqhahpgenjkbiukurvdwapuewrbehczrtswubthodv";
    //printf("isPalindromeString %d\n", isPalindromeString(s));

    time_t t1 = 0, t2 = 0;
    
    printf("String = %s\n", s);

    t1 = time(NULL);

    char *ret = longestPalindrome_dp(s);
    //char *ret = longestPalindrome(s);

    t2 = time(NULL);

    printf("longestPalindrome=[%s], tmDiff [%ld]\n", ret, t2 - t1);
    
    return 0;
}




