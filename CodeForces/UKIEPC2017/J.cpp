#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const long long maxn = 2e3+100;
struct ND {
    long long a,b;
} a[maxn];

bool cmp(ND a1,ND a2) {
    return a1.b < a2.b;
}

int main() {
    long long n,kase=0,tmp;
    cin >> n;
    while(n--) {
        cin >>  tmp;
        if(tmp) {
            a[kase].a = 1;
            a[kase].b = tmp;
        } else {
            a[kase].a = 2;
            a[kase].b = 1;
        }
        kase++;
    }
    sort(a,a+kase,cmp);
    long long out1,out2,ans;
    long long maxnn = a[kase-1].b;
    out2 = out1 = ans = 0;
    out2 = maxnn;
    for(long long i=0; i<kase; i++) {
        out1 += maxnn/a[i].b * a[i].a;
        if(out1 >= maxnn) {
            ans += out1/maxnn;
            out1 %= maxnn;
        }
    }
    double anss = ans+(out1*1.0)/out2;
    printf("%06lf\n",ans);
    return 0;
}

