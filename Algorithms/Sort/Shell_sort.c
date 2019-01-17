#include <stdio.h>

void print(int *number);

int main()
{
    int number[10] = {8,3,4,2,5,0,6,7,1,9};
    print(number);
    for(int span = 10/2; span > 0; span /= 2)
    {
        int start = span,end = span*2;
        while(start < end)
        {
            for(int i=start; i<10; i+=span)
            {
                int key = number[i],j=i-span;
                while(j>=0 && key < number[j])
                {
                    number[j+span] = number[j];
                    number[j] = key;
                    j-=span;
                }
            }
            ++start;
        }
        print(number);
    }
    return 0;
}

void print(int *number)
{
    for(int i=0; i<10; i++)
        printf("%d\t",number[i]);
    printf("\n");
    return;
}
