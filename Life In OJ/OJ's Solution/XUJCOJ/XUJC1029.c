#include <stdio.h>
#include <string.h>
#include <limits.h>

#define N 1001

int main()
{
    int n;
    while(scanf("%d",&n) != EOF && n>0)
    {
        int Tmp,cont=0;
        int In[N] = {0};
        int flower[N] = {0};
        while(n--)
        {
            scanf("%d",&Tmp);
            if(Tmp%2) flower[cont++] = Tmp;
        }
        int dp[cont] , max = 0;
        memset(dp,0,sizeof(int)*cont);
        for(int i=0; i<cont; i++)
        {
            for(int j=i-1; j>=0; j--)
            {
                if(flower[i] >= flower[j])
                    dp[i] = dp[j] > dp[i] ? dp[j] : dp[i];
            }
            dp[i] += 1;
            max = dp[i] > max? dp[i] : max ;
        }
        printf("%d\n",max);
    }
    return 0;
}
