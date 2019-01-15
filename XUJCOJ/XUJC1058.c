#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define N 1000001

bool isNotPrime[N]={0};
int Prime[N]={0};
int times[N]={0};
int temp[N] = {0};

int main()
{
    
    //finde prime
    int nums=0;  //markdown the prime's number
    isNotPrime[0] = isNotPrime[1] = 1;
    for(int i=0; i<N; i++)
    {
        if(!isNotPrime[i]) Prime[nums++]=i;
        for(int j=0; j<nums&&i*Prime[j]<N; j++)
        {
            isNotPrime[Prime[j]*i] = 1;
            if(i%Prime[j]==0) break;
        }
    }
    //finde prime clear
    for(int i=0; i<nums; i++)
    {
        for(int j=2; j*Prime[i]<N; j++)
        {
            times[j*Prime[i]]+=1;
        }
    }
    //get position number
    for(int i=0; i<N; i++)
    {
        temp[i] = temp[i-1] + times[i]%2;
    }
    printf("over sir\n");
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int a,b,sum=0;
        scanf("%d%d",&a,&b);
        /*
        for(int i=a; i<=b; i++)
        {
            if(times[i]%2) sum++;
        }
        */
        printf("%d\n",temp[b]-temp[a]+times[a]%2);
    }
    return 0;
}
