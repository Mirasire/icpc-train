#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if(a*100 == b*(100-a)) printf("draw\n");
        else printf("%s\n",a*100 > b*(100-a) ? "TuTu":"Maoxian");
    }
    return 0;
}
