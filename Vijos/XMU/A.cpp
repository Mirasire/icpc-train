#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;

typedef long long ll;

int main() {
    ll a,p,b,x=0;
    ll tmp;
    freopen("in","r",stdin);
    while(scanf("%lld%lld%lld",&a,&p,&b) == 3) {
        if( (!(a%p) || !(p%a) ) && a!=1 && p !=1 ) printf("daishixiongzuishuai\n");
        else {
            x = 0;
            tmp = 1;
            while(1) {
                if(!((int)abs(tmp - b) % p)) break;
                x++;
                tmp = tmp*a;
            }
            printf("%lld\n",x);
        }
    }
    return 0;
}
//moxianbao

            

