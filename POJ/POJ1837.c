//Accepted 1.15 -- by Meskill

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 15001

#define BLANCE 7500

/******************************
 * Reason:                      
 * weight's range = 1~25
 * hook's range = -15~15
 * number of weights = 2~20
 * number of hooks = 2~20
 * so BALANCE = 20(all in the far lenth)*25(all is the max weight)*15(all hook's number) = 7500
 * the range should be doubled 7500*2 = 15000,because of hook's range have miner's number.
 ******************************/

int Length[20] = {0}; //Lenth -15~15
int G[20] = {0};    //weight 1~25
int dp[22][N] = {0};

int main()
{
    int C,W;
    while(scanf("%d%d",&C,&W)==2)
    {
        memset(dp,0,sizeof(dp[0][0])*20*N);
        dp[0][BLANCE]=1;
        // if every hook is empty,it's sure that it's balance 
        // in other way, the base status is dp[0][BLANCE]=1;
        for(int i=0; i<C; i++) scanf("%d",Length+i);
        for(int i=0; i<W; i++) scanf("%d",G+i);
        for(int i=0; i<W; i++)
        {
            for(int j=0; j<N; j++)
            {
                if(dp[i][j])
                {
                    for(int  t=0; t<C; t++)
                    {
                        dp[i+1][j+Length[t]*G[i]] += dp[i][j];
                    }
                }
            }
        }
        printf("%d\n",dp[W][BLANCE]);
    }
    return 0;
}

