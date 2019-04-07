#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ll t;
    scanf("%lld",&t);
    while(t--)
    {
        ll n,mod;
        ll x=0,y=0,gcd=0;
        scanf("%lld%lld",&n,&mod);
        int a = n,b = n+1,c=n+2;
        if(a%2==0)
        {
            a/=2;
            if(a%3==0) a/=3;
            else if(b%3==0) b/=3;
            else c/=3;
        }
        else
        {
            b/=2;
            if(a%3==0) a/=3;
            else if(b%3==0) b/=3;
            else c/=3;
        }
        a%=mod;
        b%=mod;
        c%=mod;
        printf("%lld\n",a%mod*b%mod*c%mod%mod);
    }
    return 0;
}
