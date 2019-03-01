#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#define LOCAL
using namespace std;

typedef long long ll;
map<string,ll> Adt;

ll mod=1LL<<47;

ll mul(ll a, ll b)
{
    ll ans=0;
    while(b)
    {
        if(b%2) ans=(ans+a)%mod;
        b >>= 1;
        a=(a+a)%mod;
    }
    return ans%mod;
}

int main()
{
#ifdef LOCAL
    freopen("in","r",stdin);
    freopen("out","w",stdout);
#endif
    string tag;
    string lable1;
    string lable2;
    string NewLable;
    ll number;
    while(cin >> tag)
    {
        if(tag == "def")
        {
            cin >> NewLable >> number;
            Adt[NewLable]=number;
            cout << NewLable <<" = "<< Adt[NewLable] << endl;
        }
        else
        {
            cin >> lable1 >> lable2;
            if(tag == "mul")
            {
                Adt[lable1] = mul(Adt[lable1],Adt[lable2]);
            }
            else if(tag == "sub")
            {
                Adt[lable1] = (Adt[lable1]-Adt[lable2]+mod)%mod;
            }
            else if(tag == "div")
            {
                Adt[lable1] = Adt[lable1]/Adt[lable2];
            }
            else if(tag == "add")
            {
                Adt[lable1] = (Adt[lable1]+Adt[lable2])%mod;
            }
            else if(tag == "mod")
            {
                Adt[lable1] = Adt[lable1]%Adt[lable2];
            }
            cout << lable1 <<" = "<< Adt[lable1] << endl;
        }
    }
    return 0;
}
