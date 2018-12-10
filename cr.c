#include <stdio.h>

void print(int *pnumber);

int main()
{
    int number[6] = {5,3,7,6,2,3};
    print(number);
    for(int i=2,j; i<6; i++)
    {
        for(j=i; j>0; j--)
        {
            if(number[j-1] > number[i]) break;
        }
        int temp = number[i];
        number[i] = number[j];
        number[j] = temp;
        print(number);
    }
    return 0;
}

void print(int *pnumber)
{
    for(int i=0; i<6; i++)
    {
        printf("%d\t",pnumber[i]);
    }
    printf("\n");
    return;
}
