#include <stdio.h>

typedef long long ll;

ll mod;

ll Qmutiply(ll a, ll n)
{
    ll back = 0;
    while(n)
    {
        if(n&1) back = (back+a) % mod;
        a  = (a+a)%mod;
        n/=2;
    }
    return back;
}

ll Qfactor(ll a,ll n)
{
    ll back = 1;
    while(n)
    {
        if(n&1) back = Qmutiply(back,a);
        a = Qmutiply(a,a);
        n/=2;
    }
    return back;
}

int main()
{
    ll a,b,c;
    scanf("%lld%lld%lld%lld",&a,&b,&c,&mod);
    printf("%lld\n", Qfactor(a,Qfactor(b,c)));
    return 0;
}
