#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <cmath>
using namespace std;

typedef long long ll;
const ll maxn = 5e4+100;
ll block;
ll a[maxn];
ll A;
ll cnt[maxn];

struct TYPE{
    ll num,l,r;
} sigment[maxn];
struct {
    ll pa,pb;
} anss[maxn];

ll getGcd(ll a,ll b) {
    return b? getGcd(b,a%b) : a;
}

bool cmp(TYPE &a, TYPE &b) {
    return (a.l/block == b.l/block) ? a.r < b.r: a.l <b.l;
}

void add(ll x) {
    A -= cnt[a[x]]*(cnt[a[x]] - 1);
    cnt[a[x]]++;
    A += cnt[a[x]]*(cnt[a[x]] - 1);
}

void del(ll x) {
    A -= cnt[a[x]]*(cnt[a[x]] - 1);
    cnt[a[x]]--;
    A += cnt[a[x]]*(cnt[a[x]] - 1);
}

int main() {
    //freopen("in","r",stdin);
    ll i,n,m;
    scanf("%lld%lld",&n,&m);
    block = sqrt(n);
    for(i=1; i<=n; i++) scanf("%lld",a+i);
    for(i=1; i<=m; i++) {
        scanf("%lld%lld",&sigment[i].l, &sigment[i].r);
        sigment[i].num = i;
    }
    ll l,r,tl,tr;
    l = 1, r = 0;

    sort(sigment+1,sigment+1+m,cmp);
    for(i=0; i<=m; i++) {
        tl = sigment[i].l;
        tr = sigment[i].r;
        while(l < tl) del(l++);
        while(l > tl) add(--l);
        while(r < tr) add(++r);
        while(r > tr) del(r--);
        anss[sigment[i].num].pa = A;
        if(r == l) {
            anss[sigment[i].num].pa = 0;
            anss[sigment[i].num].pb = 1;
        }
        else anss[sigment[i].num].pb = (r-l)*(r-l+1);
    }
    ll gcd = 0;
    for(i=1; i<=m; i++) {
        gcd = getGcd(anss[i].pa,anss[i].pb); 
        printf("%lld/%lld\n",anss[i].pa/gcd,anss[i].pb/gcd);
    }
    return 0;
}
