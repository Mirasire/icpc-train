#include <stdio.h>
#include <string.h>
#include <limits.h>

int  main()
{
    int n;
    scanf("%d",&n);
    int Standard[n];
    int dp[n],out=INT_MIN;
    for(int i=0; i<n; i++) dp[i]=1;
    for(int i=0; i<n; i++) scanf("%d",Standard+i);
    for(int i=0; i<n; i++)
    {
        int max = 0;
        for(int j=i-1; j>=0; j--)
        {
            if(dp[j] > max && Standard[i]>Standard[j]) max=dp[j];
        }
        dp[i]+=max;
        if(dp[i]>out) out = dp[i];
    }
    printf("%d\n",out);
    return 0;
}
