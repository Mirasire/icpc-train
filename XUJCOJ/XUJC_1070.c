#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define N 10001

bool isNotPrime[N] = {0};
int Prime[N] = {0};

int main()
{
    int nums = 0;
    isNotPrime[0] = isNotPrime[1] = 1;
    for(int i=0; i<N; i++)
    {
        if(!isNotPrime[i]) Prime[nums++] = i;
        for(int j=0; j<nums && i*Prime[j]<N; j++)
        {
            isNotPrime[i*Prime[j]] = 1;
            if(!(i%Prime[j])) break;
        }
    }
    int n,max = INT_MIN,out=0;
    scanf("%d",&n);
    while(n--)
    {
        int in,tp;
        scanf("%d",&in);
        for(int i=nums-1; i>=0; i--)
        {
            if(!(in%Prime[i]))
            {
                tp = Prime[i];
                break;
            }
        }
        if(tp > max) 
        {
            max = tp;
            out = in;
        }
    }
    printf("%d",out);
    return 0;
}
