#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b)
{
    int temp = *a;
        *a = *b;
        *b = temp;
    return;
}

int cmp(const void *a, const void *b)
{
    return *(int *)a-*(int *)b;
}

int main()
{
    int N,M,out=-1,flag = 0;
    scanf("%d%d",&N,&M);
    int baseNumber[N];
    int changeNumber[N];
    int endNumber[N];
    for(int i=0; i<N; i++) scanf("%d",baseNumber+i);
    for(int i=0; i<N; i++) scanf("%d",changeNumber+i);
    for(int i=1; i<=N; i++)
    {
        for(int j=0; j<N; j++)
        {
            endNumber[j] = baseNumber[j]+i*changeNumber[j];
        }
        qsort(endNumber,N,sizeof(int),cmp);
        int sum = 0;
        for(int j=0; j<i; j++) sum+=endNumber[j];
        if(sum <= M) 
        {
            if(i>out) out = i;
        }
    }
    printf("%d\n",out);
    return 0;
}
