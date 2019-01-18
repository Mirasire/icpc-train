#include <stdio.h>

int main()
{
    int count[10]={0};
    for(int i=0; i<10; i++)
    {
        scanf("%d",count+i);
    }
    for(int i=1; i<10; i++)
    {
        if(count[i])
        {
            printf("%d",i);
            count[i]--;
            break;
        }
    }
    for(int i=0; i<10; i++)
    {
        if(count[i])
        {
            for(int j=0; j<count[i]; j++) printf("%d",i);
        }
    }
    printf("\n");
    return 0;
}
