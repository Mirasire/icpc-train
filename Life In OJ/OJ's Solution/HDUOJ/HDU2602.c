#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int N,P;
        long long *w,*c,*dp;
        scanf("%d%d",&N,&P);
        w = (long long  *)malloc(sizeof(long long)*N);
        c = (long long  *)malloc(sizeof(long long)*N);
        dp = (long long  *)malloc(sizeof(long long)*(P+1));
        memset(dp,0,sizeof(long long)*(P+1)); //Please Don't use sizeof(dp)
        for(int i=0; i<N; i++) scanf("%lld",w+i);
        for(int i=0; i<N; i++) scanf("%lld",c+i);
        for(int i=0; i<N; i++)
            for(int j=P; j>=*(c+i); j--)
                dp[j] = dp[j-c[i]] + w[i] > dp[j] ? dp[j-c[i]] + w[i] : dp[j] ;
        printf("%lld\n",dp[P]);
        free(dp);
        free(w);
        free(c);
    }
    return 0;
}
