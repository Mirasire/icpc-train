#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define N 1000001


bool isNotPrime[N] = {0};
int Prime[N] = {0};
int tmep_a[N] = {0};
int tmep_b[N] = {0};

void MakePrime(void)
{
    int nums=0;
    isNotPrime[0] = isNotPrime[1] = 1;
    for(int i=0; i<N; i++)
    {
        if(!isNotPrime[i]) Prime[nums++] = i;
        for(int j=0; j<nums&&i*Prime[j]<N; j++)
        {
            isNotPrime[i*Prime[j]] = 1;
            if(!(i % Prime[j])) break;
        }
    }
    return;
}

void prt(const int *arr,int lon)
{
    for(int i=0; i<lon; i++)
        printf("%d ",arr[i]);
    printf("\n");
    return;
}

int main()
{
    MakePrime();
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        int end1  = a/2,end2 = b/2;
        int numsA = 0,numsB=0;
        int i=0;
        memset(tmep_a,0,sizeof(int)*N);
        memset(tmep_b,0,sizeof(int)*N);
        while(Prime[i] <= end1)
        {
            if(!(a % Prime[i])) tmep_a[numsA++] = Prime[i];
            i++;
        }
        if(!isNotPrime[a]) tmep_a[numsA++] = a;
        //prt(tmep_a,numsA);
        
        i=0;
        while(Prime[i] <= end2)
        {
            if(!(b % Prime[i])) tmep_b[numsB++] = Prime[i];
            i++;
        }
        if(!isNotPrime[b]) tmep_a[numsB++] = b;
        

        int *time_a = (int *)malloc(sizeof(int)*numsA);
        int *time_b = (int *)malloc(sizeof(int)*numsB);
        memset(time_a,0,sizeof(int)*numsA);        
        memset(time_b,0,sizeof(int)*numsB);        
        for(int i=0; i<numsA; i++)
        {
            int Pi  = 1;
            while(Pi!=0&&!(a%Pi))
            {
                time_a[i]+=Pi;
                Pi*=tmep_a[i];
            }
        }
        
        //prt-A
        //prt(time_a,numsA); 
        
        int CaculateA = 1;
        for(int i=0; i<numsA; i++)
        {
            CaculateA *= time_a[i];
        }
        for(int i=0; i<numsB; i++)
        {
            int Pi  = 1;
            while(Pi!=0&&!(b%Pi))
            {
                time_b[i]+=Pi;
                Pi*=tmep_b[i];
            }
        }
        
        //ptr-B
        //prt(time_b,numsB); 
        
        int CaculateB = 1;
        for(int i=0; i<numsB; i++)
        {
            CaculateB *= time_b[i];
        }
        
        ///*test
        //printf("CaculateA = %d CaculateB = %d\n",CaculateA,CaculateB);
        //*/
        //printf("CaculateA-a = %d CaculateB-b = %d\n",CaculateA-a,CaculateB-b);
        //printf("a = %d b = %d\n",a,b);
        
        if((CaculateB-b) == a && (CaculateA-a) == b) printf("YES\n");
        else printf("NO\n");
        free(time_a);
        free(time_b);
    }
    return 0;
}
