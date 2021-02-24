#if 1
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int x = 0;
    int total = 0, count = 0;

    scanf("%d", &x);

    if(x < 8 || x > 100){
        printf("count = %d\n", count);
        return -1;
    }

    if (x >= 8 && x<= 100)
    {
        int r5 = 0, r5d = 0, r2 = 0, r2d = 0, r1 = 0;

        for(r5 = x / 5; r5 > 0; r5 --)
        {
            for(r2 = (x - r5 * 5) / 2; r2 > 0; r2 --)
            {
                r1 = x - r5 * 5 - r2 * 2;

                if(r5 > 0 && r2 > 0 && r1 > 0){
                    total = r5 + r2 + r1;
                    count ++;
                    printf("fen5:%d, fen2:%d, fen1:%d, total:%d\n", r5, r2, r1, total);
                }
            }
        }

        printf("count = %d\n", count);
        
    }

    return 0;
}
#else

#include<stdio.h>

int main()
{
    int x;
    int i,j,k;
    int count=0;
    scanf("%d",&x);
    
    for(i=x/5;i>0;i--)
    {
        for(j=x/2;j>0;j--)
        {
            for(k=x;k>0;k--)
            {
                if(i*5+j*2+k*1==x)
                {
                    printf("fen5:%d, fen2:%d, fen1:%d, total:%d\n",i,j,k,i+j+k);
                    count++;
                }
            }
        }
    }

   printf("count = %d\n",count);
}
#endif