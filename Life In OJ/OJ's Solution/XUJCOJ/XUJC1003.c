/*
审题十分重要，前面案例没过是因为没看到题目的
************
**多组案例**
************
*/

#include <stdio.h>

int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
        int Number[25] = {0},cout =1;
        while(n--)
        {
            int st,ed;
            scanf("%d%d",&st,&ed);
            for(int i=st; i<ed; i++) 
            {
                Number[i]++;
                if(Number[i]>cout) cout=Number[i];
            }
        }
        printf("%d\n",cout);
    }
    return 0;
}
