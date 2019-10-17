#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1e5+100;
typedef long long int ll;
ll s[maxn<<2],lazy[maxn<<2];
ll out;

void up(int index) {
    s[index] = s[index<<1] + s[index<<1|1];
}

void down_lazy(int index,int l,int r) {
    if(lazy[index]) {
        int mid = (l+r)/2;
        lazy[index<<1] = lazy[index<<1|1] = lazy[index];
        s[index<<1] = lazy[index]*(mid-l+1);
        s[index<<1|1] = lazy[index]*(r-mid);
        lazy[index] = 0;
    }
}

void modify(int index,int L,int R,int l,int r,int def) {
    if(l>=L && r<=R) {
        s[index] = def*(r-l+1);
        lazy[index] = def;
        return;
    }
    int mid = (l+r)/2;
    down_lazy(index,l,r);
    if(mid >= L) modify(index<<1,L,R,l,mid,def);
    if(mid < R) modify(index<<1|1,L,R,mid+1,r,def);
    up(index);
}

void init(int n) {
    out = 0;
    memset(s,0,sizeof(s));
    memset(lazy,0,sizeof(lazy));
    modify(1,1,n,1,n,1);
}

int main() {
    int i,t,kase=0,n,m;
    ll beg,ed,tmp;
    scanf("%d",&t);
    while(t--) {
        printf("Case %d: The total value of the hook is ",++kase);
        scanf("%d%d",&n,&m);
        init(n);
        for(i=1; i<=m; i++) {
            scanf("%lld%lld%lld",&beg,&ed,&tmp);
            modify(1,beg,ed,1,n,tmp);
        }
        printf("%lld.\n",s[1]);
    }
    return 0;
}
