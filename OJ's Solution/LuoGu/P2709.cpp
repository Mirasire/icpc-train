#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long int ll;
struct TYPE {
    ll num,l,r;
};

const int maxn = 5e4+10;
ll arr[maxn];
TYPE si[maxn];
ll ans[maxn];
ll cnt[maxn];
ll block,sum;

bool cmp(const TYPE &a,const TYPE &b) {
    return (a.r/block) == (b.r/block)? a.l < b.l: a.r < b.r;
}

void add(ll index) {
    cnt[arr[index]]++;
    sum += 2*cnt[arr[index]] - 1;
}

void del(ll index) {
    //WA_reason: if(cnt[arr[index]])
    cnt[arr[index]]--;
    sum -= 2*cnt[arr[index]] + 1;
}


int main() {
    //freopen("in","r",stdin);
    ll i,n,m,k;
    scanf("%lld%lld%lld",&n,&m,&k);
    block = sqrt(n);
    for(i=0; i<n; i++) scanf("%lld",arr+i);
    for(i=0; i<m; i++) {
        scanf("%lld%lld",&si[i].l,&si[i].r);
        si[i].l--;
        si[i].r--;
        si[i].num = i;
    }
    sort(si,si+m,cmp);

    ll  l = 1,r = 0,pl,pr;
    sum = 0;
    for(i=0; i<m; i++) {
        pl = si[i].l;
        pr = si[i].r;
        while(l > pl) {
            l--;
            add(l);
        }
        while(l < pl) {
            del(l);
            l++;
        }
        while(r < pr) {
            r++;
            add(r);
        }
        while(r > pr) {
            del(r);
            r--;
        }
        ans[si[i].num] = sum;
    }
    for(i=0; i<m; i++) printf("%lld\n",ans[i]);
    return 0;
}


