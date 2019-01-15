#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    while(n>0&&m>0)
    {
        int *SchoolCost = (int *)malloc(sizeof(int)*m);
        float *probability = (int *)malloc(sizeof(int)*m);
        float *dp = (int *)malloc(sizeof(int)*(n+1));
        memset(SchoolCost,0,sizeof(int)*m);
        memset(probability,0,sizeof(int)*m);
        memset(dp,0,sizeof(int)*(n+1));
        for(int i=0; i<m; i++)
        {
            float temp = 0;
            scanf("%d%f",SchoolCost+i,temp);
            *(probability+i) = 1-temp;
        }
        free(dp);
        free(SchoolCost);
        free(probability);
    }
    return 0;
}
