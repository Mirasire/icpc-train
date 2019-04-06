#include <iostream>
using namespace std;

int main()
{
    int n,p,add = 0, out = 0, man = 0;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&p);
        if(!p && man) add++,out+=man;
        else if(p) man++;
    }
    printf("%d",out);
    return 0;
}
