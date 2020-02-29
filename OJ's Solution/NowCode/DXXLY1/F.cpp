#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    long long int x1,y1,x2,y2,x3,y3,s;
    freopen("in","r",stdin);
    while(scanf("%lld%lld%lld%lld%lld%lld",&x1,&y1,&x2,&y2,&x3,&y3) != EOF) {
        //abs!!
        s = 11 * abs(((x2-x1)*(y3-y1) - (x3-x1)*(y2-y1)));
        printf("%lld\n",s);
    }
    return 0;
}
