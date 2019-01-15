#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int in;
        scanf("%d",&in);
        while(in > 9)
        {
            int temp = in % 10;
            in = in/10+temp;
        }
        printf("%d\n",in);
    }
    return 0;
}
