#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n,lon,out=0,one=0,zero=0;
    scanf("%d ",&n);
    char Ch;
    for(int i=0; i<n; i++)
    {
        scanf("%c",&Ch);
        if(Ch == '1') one++;
        else if(Ch == '0') zero++;
    }
    printf("%d\n",n-2*min(one,zero));
    return 0;
}
