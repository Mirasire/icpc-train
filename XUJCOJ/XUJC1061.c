#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int girl,boy,in;
        int g[120] = {0};//girl
        int b[120] = {0};//boy
        scanf("%d",&boy);
        for(int i=0; i<boy; i++)
        {
            scanf("%d",&in);
            b[in]++;
        } 
        scanf("%d",&girl);
        for(int i=0; i<girl; i++)
        {
            scanf("%d",&in);
            g[in]++;
        }
        int out = 0;
        for(int i=100; i>=0; i--)
        {
            if(b[i])
            {
                int end = i-10;
                end =  end>=0? end : 0;//important!!
                for(int j=i+10; j>=end&&b[i]; j--)
                {
                    while(g[j]&&b[i])
                    {
                        int add = j*i;
                        out+=add;
                        g[j]--;
                        b[i]--;
                    }
                }
            }
        }
        printf("%d\n",out); 
    }
    return 0;
}
