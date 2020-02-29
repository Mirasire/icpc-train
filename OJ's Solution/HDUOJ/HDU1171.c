#include<stdio.h>
#include<stdlib.h>
#include<string.h>

static int nums[50000];

int main()
{
    int n;
    while(~scanf("%d",&n),n>0)
    {
        int sum = 0,overlap,i=0;
        while(n--)
        {
            scanf("%d%d",nums+i,&overlap);
            for(int j=1; j<overlap; j++)
                *(nums+i+j) = *(nums+i);
            sum += *(nums+i) * overlap;
            i+=overlap;
        }
        int package = sum/2,ed = i-1;
        //printf("%d\n",package);
        int *dp = (int *)malloc(sizeof(int)*(package+1));
        memset(dp,0,sizeof(int)*(package+1));
        for(int i=0; i<ed; i++)
        {
            for(int j=package; j>=nums[i]; j--)
            {
                if(j - nums[i] >= 0)
                    dp[j] = dp[j-nums[i]] + nums[i] > dp[j] ? dp[j-nums[i]] + nums[i] : dp[j];
            }
        }
        printf("%d %d\n",sum-dp[package],dp[package]);
        free(dp);
    }
    return 0;
}


/*
conclution:
输入未确定数字却有明确的结束标志的时候判断条件
要用
while(~scanf("%d",&n),n>0)
如果改用
while(scanf("%d",&n)&&n>0)
可能会出错(时间效率过低或者编译器反向编译
)
*/
