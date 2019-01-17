//TLE --version
#include <stdio.h>
#include <string.h>

int temp[10];

int cut(int number)
{
    int mod;
    while(number)
    {
        mod = number%10;
        if(temp[mod]!=0) return 0;
        else temp[mod]++;
        number/=10;
    }
    return 1;
}

int main()
{
    int flag =1;
    int sum=0;
    for(int i=12345678; i<=87654321; i++)
    {
        memset(temp,0,sizeof(temp[0])*10);
        temp[0] = temp[9] = 1;
        if(cut(i))  
        {
            sum++;
            printf("%d\n",i);
        }
    }
    printf("%d\n",sum);
    return 0;
}
