#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,c,h;
        scanf("%d%d",&n,&m);
        int dp[100001] = {0};
        for(int i=0; i<n; i++) 
        {
            scanf("%d%d",&c,&h);
            for(int j=m; j>=h; j--)
            {
                dp[j] = (dp[j-h] + c > dp[j])? dp[j-h] + c : dp[j];
            }
            dp[h] = dp[h] > c ? dp[h]:c;
        }
        printf("%d\n",dp[m]);
    }
    return 0;
}
