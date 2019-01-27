#include <stdio.h>
#include <limits.h>

int main()
{
    int n,sum =0;
    scanf("%d",&n);
    int sweet[n],down=n;
    while(n--)
    {
        scanf("%d",sweet+n);
        sum+=sweet[n];
    }
    int average = sum / down;
    average-=1;
    int temp = 0,end=2;
    sum=INT_MAX;
    while(end--)
    {
        int temp=0;
        average+=1;
        for(int i=0; i<down; i++)
        {
            if(sweet[i] != average) temp += sweet[i] < average ? average-sweet[i]-1 : sweet[i] - average -1; 
        }
        sum = sum < temp? sum : temp;
    }
    printf("%d",sum);
    return 0;
}
