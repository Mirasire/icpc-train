#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <cmath>
using namespace std;

typedef long long int ll;
const int maxn = 200100;
ll k[maxn],out[maxn],times[maxn],b[maxn];

struct DIS {
    int l,r;
} dis[maxn];

void dp(int l,int r) {
    for(int i=r; i>=l; i--) {
        if(i + k[i] > dis[b[i]].r) {
            times[i] = 1;
            out[i] = i + k[i];
        } else {
            times[i] = 1+times[i+k[i]];
            out[i] = out[i+k[i]];
        }
    }
    return;
}

int main() {
    freopen("in","r",stdin);
    int i,n,m;
    scanf("%d",&n);
    for(i=0; i<n; i++) scanf("%lld",k+i);

    //cut arr
    int block = sqrt(n),s = 0;
    if(block*block < n) block++;
    for(i=0; i<n; i+=block) {
        dis[s].l = i;
        dis[s++].r = i+m-1;
    }

    if(s<block) {
        dis[s].l = i-block+1;
        dis[s++].r = n-1;
    }
    
    for(i=0,s=0; i<n; i++) {
        if(i>dis[s].r) s++;
        b[i] = s;
    }
    
    dp(0,n-1);

    scanf("%d",&m);
    int op,query,j,def,index;
    ll ans;
    while(m--) {
        scanf("%d",&op);
        if(op == 1) {
            scanf("%d",&query);
            ans = times[query],index = out[query];
            for(i=b[i]; i<m&&index<n; i++,index = out[index]) ans += times[index];
            printf("%lld\n",ans);
        } else {
            scanf("%d%d",&j,&def);
            k[j] = def;
            dp(dis[b[j]].l,dis[b[i]].r);
        }
    }
    return 0;
}

