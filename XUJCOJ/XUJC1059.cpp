#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        long long int m,a,b,out = 1;
        cin >> m >> a >> b;
        while(b)
        {
            if(b%2) out = out*a%m;
            b/=2;
            a = a*a%m;
        }
        printf("%lld\n",out==0? m : out );
    }
    return 0;
}
