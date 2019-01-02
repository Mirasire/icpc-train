#include <stdio.h>
#include <limits.h>

int rt_Type(int a)
{
    a/=1000;
    switch(a)
    {
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 3;
    }
    return 0;
}

int main()
{
    int input,max = INT_MIN,min=INT_MAX; 
    int a[4] = {0};
    for(int i=0; i<12; i++)
    {
        scanf("%d",&input);
        int index = rt_Type(input);
        a[index]++;
        if(input > max) max =input;
        if(input < min) min =input;
    }
    printf("1-group:%d\t2-group:%d\t3-group:%d\t\n",a[1],a[2],a[3]);
    printf("max = %d\t min = %d\t\n",max,min);
    return 0;
}
