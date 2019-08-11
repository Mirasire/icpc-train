#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <utility>
#define  prt(x)  prllf(#x " = %lld\n",x)
using namespace std;

typedef long long ll;
const ll maxn = 4e5+100;
ll x[maxn],y[maxn],a[maxn<<1],L[maxn],R[maxn];
ll A1,B1,C1,M1;
ll A2,B2,C2,M2;
struct ND {
    ll l,r;
    ll sum,lazy;
};
ND stn[maxn<<3];

void build(ll index,ll l,ll r) {
    //cout << l << " " << r << endl;
    stn[index].l = l;
    stn[index].r = r;
    stn[index].sum = stn[index].lazy = 0;
    if(l+1 == r) return;
    ll mid = (l+r)/2;
    build(index<<1,l,mid);
    build(index<<1|1,mid,r);
}

void up(ll index) {
    if(stn[index].l+1 == stn[index].r) return;
    stn[index].sum = stn[index<<1].sum + stn[index<<1|1].sum;
}

void down_lazy(ll index) {
    if(stn[index].lazy == 0) return;
    if(stn[index].l+1 == stn[index].r) return;
    stn[index<<1].lazy += stn[index].lazy;
    stn[index<<1].sum += stn[index].lazy*(a[stn[index<<1].r] - a[stn[index<<1].l]);
    stn[index<<1|1].lazy += stn[index].lazy;
    stn[index<<1|1].sum += stn[index].lazy*(a[stn[index<<1|1].r] - a[stn[index<<1|1].l]);
    stn[index].lazy = 0;
}

void modify(ll index,ll l,ll r) {
    if(stn[index].l == l && stn[index].r == r) {
        //prt(index);
        stn[index].sum += a[r] - a[l];
        stn[index].lazy++;
        return;
    }
    ll mid = (stn[index].l+stn[index].r)/2;
    down_lazy(index);
    if(mid >= r) modify(index<<1,l,r);
    else if(mid <= l) modify(index<<1|1,l,r);
    else {
        modify(index<<1,l,mid);
        modify(index<<1|1,mid,r);
    }
    up(index);
}

ll query(ll index,ll num) {
    if(stn[index].l + 1 == stn[index].r) {
        ll tmp = stn[index].sum / (a[stn[index].r] - a[stn[index].l]);
        return (ll)(a[stn[index].l] + (num-1)/tmp);
    } 
    ll mid = (stn[index].l+stn[index].r) >> 1;
    down_lazy(index);
    if(stn[index<<1].sum >= num) return query(index<<1,num); 
    else return query(index<<1|1,num - stn[index<<1].sum); 
}
    
void solve(vector<pair<ll,ll>> ves) {
    ll n = ves.size();
    ll tot = 0;
    for(ll i=0; i<n; i++) {
        ves[i].second++;
        a[tot++] = ves[i].first;
        a[tot++] = ves[i].second;
    }
    sort(a,a+tot);
    tot = unique(a,a+tot) - a;
    build(1,0,tot-1);
    for(ll i=0; i<n; i++) {
        L[i] = lower_bound(a,a+tot,ves[i].first) - a;
        R[i] = lower_bound(a,a+tot,ves[i].second) - a;
    }
    ll idx = 0;
    //prllf("build ok\n");
    for(ll i=0; i < n; i++) {
        idx +=  ves[i].second - ves[i].first;
        modify(1,L[i],R[i]);
        //prllf("modify ok\n");
        printf("%lld\n",query(1,(idx+1)/2));
    }
}

int main() {
    ll n;
    while(scanf("%lld",&n) == 1) {
        scanf("%lld%lld%lld%lld%lld%lld",x+1,x+2,&A1,&B1,&C1,&M1);
        for(ll i=3; i<=n; i++) x[i] = (A1*x[i-1] + B1*x[i-2] + C1) % M1;
        scanf("%lld%lld%lld%lld%lld%lld",y+1,y+2,&A2,&B2,&C2,&M2);
        for(ll i=3; i<=n; i++) y[i] = (A2*y[i-1] + B2*y[i-2] + C2) % M2;
        vector<pair<ll,ll>> ves;
        ll l,r;
        for(ll i=1; i<=n; i++) {
            l = min(x[i],y[i]) + 1;
            r = max(x[i],y[i]) + 1;
            ves.push_back(make_pair(l,r));
        }
        solve(ves);
    }
    return 0;
}
