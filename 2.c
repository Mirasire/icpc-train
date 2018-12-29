#include <stdio.h>

int main()
{
    int number[1000];
    int index = 0,sum = 0;  
    for(int i=0; i<=100; i++)
    {
        if(i%10 == 7)
        {
            sum += i;
            number[index] = i;
            index++;
        }
    }
    for(int i=0,j=1; i<index; j++,i++)
    {
        printf("%d\t",number[i]);
        if(j%4 == 0) printf("\n");
    }
    printf("\n");
    index--;
    printf("average  = %.1f",sum*1.0/index);
    return 0;
}
