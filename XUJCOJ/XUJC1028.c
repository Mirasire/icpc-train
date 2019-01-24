#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int m,n,index,number;
        scanf("%d%d",&m,&n);//m is now floor , n is people's number
        int floor[16] = {0};
        for(int i=0; i<n; i++)
        {
            scanf("%d%d",&index,&number);
            floor[index] += number;
        }
        int in=0,last=0,out = (m-1)*2;
        for(int i=m; i>1; i--)
        {
            in += floor[i];
            if(in >= 11) break;
            out += floor[i];
            last += floor[i];
        }
        out+= in>=11? 11-last : 0;
        printf("%d\n",out);
    }
    return 0;
}
