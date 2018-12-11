#include <stdio.h>

void print(int *pnumber);

int main()
{
    int number[6] = {5,3,7,6,2,3};
    print(number);
    for(int i=1; i<6; i++)
    {
        int key = number[i],j=i-1;
        while(j >= 0 && number[j] > key)
        {
            number[j+1] = number[j];
            number[j--] = key;
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
