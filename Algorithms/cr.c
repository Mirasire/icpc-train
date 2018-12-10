#include <stdio.h>

void print(int *pnumber);

int main()
{
    int number[6] = {5,3,7,6,2,3};
    print(number);
    for(int i=1; i<6; i++)
    {
        for(int j=i; j>=0; j--)
        {
            if(number[j-1] > number[j])
            {
                int temp = number[j];
                number[j] = number[j-1];
                number[j-1] = temp;
            }
            else
            {
                break;
            }
        }
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
