# Exgcd

由贝祖等式得 ：
$$
 gcd(a,b) =  x * a + y * b
$$

To solve the x & y;

```c++
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
```
首先

$$
gcd(b,a\%b) = gcd(a,b)
$$

由这个等式我们可以推出

上一个状态：
$$
gcd(a,b) = x*a+y*b;
$$

下一个状态:

$$
gcd(b,a\%b) = x1 * b + y2*a\%b;
$$

归纳可得：
$$
    x1 * b + (a - [a/b]*b) * y2
=   y2 * a + (x1 - [a/b]*y2) * b
$$

所以：
$$
x = y2;
y = x1 - [a/b] * y2;
$$

##### 因此我们可以靠这个来求得a,b的逆元