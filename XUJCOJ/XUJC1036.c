#include <stdio.h>

int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
        int number[n];
        for(int i=0; i<n; i++) scanf("%d",number+i);
        for(int i=n-1; i>=0; i--) printf("%d ",*(number+i));
        printf("\n");
    }
    return 0;
}
