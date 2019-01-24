#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define N 1000001

typedef struct 
{
    bool flag;
    int m; //fist fond
    int number;
    int st;
    int ed;
    int lenth;
} Arr;

Arr arr[N] = {0};
int stack[4] = {0/*used max*/,0/*new max*/,INT_MAX,INT_MAX};

int main()
{
    int n,in,cnt=1,step=1;
    int max = INT_MIN,min = INT_MAX;
    int small=1;// 1+3 0+3
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&in);
        arr[in].number++;
        if(arr[in].st == 0) 
        {
            arr[in].st=i;
            arr[in].m=cnt++;
        }
        arr[in].ed=i;
        arr[in].lenth = arr[in].ed-arr[in].st+1;
        if(arr[in].number >= max)   
        {
            max = arr[in].number;
            stack[(step++)%2] = max;
            if(stack[0] == stack[1]) 
            {
                if(arr[in].lenth < stack[2]) stack[2] = arr[in].lenth;
            }
            else stack[2] = arr[in].lenth;
        }
    }
    //printf("%d %d %d\n",stack[0],stack[1],stack[2]);
    min = stack[2];
    //printf("%d %d\n",max,min);
    int out,fist = INT_MAX;
    for(int i=1; i<N; i++)
    {
        if( arr[i].number == max && arr[i].lenth == min)
        {
            if(arr[i].m < fist )
            {
                fist = arr[i].m;
                out = i;
            }
        }
    }
    printf("%d %d\n",arr[out].st,arr[out].ed);
    return 0;
}
