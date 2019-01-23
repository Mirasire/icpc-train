#include <stdio.h>

int main()
{
    int sum=0,n;
    int in;
    scanf("%d",&n);
    for(int i=0; i<n; i++) 
    {
        scanf("%d",&in);
        sum+=in;
    }
    printf("%d",sum/n);
    return 0;
}

        


