#include <stdio.h>
#define N 1000001

int pick[N]={0};
int inde[N]={0};

int main()
{
    for(int i=2; i<N; i++)
    {
        if(!inde[i])
            for(int j=2*i; j<N; j+=i)     ++inde[j];
        pick[i] = pick[i-1] + inde[i]%2;
    }
    int n=0;
    scanf("%d",&n);
    while(n--)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        printf("%d\n",pick[b]-pick[a]+inde[a]%2);
    }
    return 0;
}
