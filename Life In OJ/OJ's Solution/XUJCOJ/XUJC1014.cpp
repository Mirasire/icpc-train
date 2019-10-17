//Double Type is important
#include <algorithm> 
#include <stdio.h>
using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        double input[6] = {0};
        for(int i=0; i<6; i++) 
            scanf("%lf",input+i);
        sort(input,input+6);
        if(input[5]+input[4] > input[1]+input[2]+input[3]) 
            printf("ZSW is the Winner!\n");
        else 
            printf("What a sad story!\n");
    }
    return 0;
}
