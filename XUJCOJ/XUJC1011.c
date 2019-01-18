#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int index;
        scanf("%d",&index);
        long long a = pow(4,index);
        printf("%lld\n",a/3);
    }
    return 0;
}


//Tips.
//(4^n - 1)%3==0;
/*
 * Reason
 * -------------
 * if index = 1
 * map = 2*2 -->finde 4 is good number
 * of course s = 1
 * if index = 2
 * map = 4*4 -->finde 16 is good number
 * of course s = 5
 * if index = 3
 * map = 8*8 --> finde 
 *
 *  */
