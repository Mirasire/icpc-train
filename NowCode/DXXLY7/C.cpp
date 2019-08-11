//IMP
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <limits.h>
using namespace std;

typedef long long ll;
const ll m_size = 1e5+100,m_pay = 230;
ll tcnt[m_pay];

struct ND{
    ll h,c,p;
};
ND kn[m_size];

bool cmp(ND a,ND b) {
    return a.h==b.h? a.c < b.c : a.h < b.h;
}

int main() {
    int t;
    ll all,cres;
    while(~scanf("%d",&t)) {
        memset(tcnt,0,sizeof(tcnt));
        all = cres = 0;
        for(int i=0; i<t; i++) {
            scanf("%lld%lld%lld",&kn[i].h,&kn[i].c,&kn[i].p);
            tcnt[kn[i].c] += kn[i].p;
            cres += kn[i].p;

        }
        sort(kn,kn+t,cmp);
        ll out = INT64_MAX,res2 = 0;
        ll hidx = t-1;
        ll hest = kn[t-1].h;
        while(hidx>=0) {
            ll hcnt=0,hsum=0;
            while(hest == kn[hidx].h) {
                tcnt[kn[hidx].c] -= kn[hidx].p;
                hcnt += kn[hidx].p;
                hsum += kn[hidx].p*kn[hidx].c;
                hidx--;
            }
            hest = kn[hidx].h; //POINT
            ll res1=0;
            ll cut = max(0ll,cres-2*hcnt+1);
            for(int i=0; i<=200; i++) {
                if(cut==0) break;
                if(tcnt[i]) {
                    if(tcnt[i] < cut) { 
                        res1 += tcnt[i]*i;
                        cut -= tcnt[i];
                    } else {
                        res1 += cut * i;
                        cut = 0;
                    }
                }
            }
            out = min(out,res1+res2);
            res2 += hsum;
            cres -= hcnt; //POINT
        }
        printf("%lld\n",out);
    }
    return 0;
}
