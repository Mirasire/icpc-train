//This is The Template

typedef long long ll;

ll Exgcd(ll a,ll b,ll &x, ll &y)
{
    if (b==0)
    {
        x=1,y=0;
        return a; // this is GCD(great common divisor)
    }
    ll q = gcd(b,a%b,y,x); //already swap the x&&y
    y -= a/b*x;
    return q;
}
