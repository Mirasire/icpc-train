#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;

typedef long long int ll;
const int maxn = 1e5+200;
ll s[maxn<<2],lazy[maxn<<2];

void up(int index) {
    s[index] = s[index << 1] + s[index << 1 | 1];
}
void down(int index,int l,int r) {
    if(lazy[index]) {
        int mid = (l+r)/2;
        lazy[index << 1] += lazy[index];
        lazy[index << 1 | 1] += lazy[index];
        s[index << 1] += lazy[index] * (mid - l + 1);
        s[index << 1 | 1] += lazy[index] * (r - mid);
        lazy[index] = 0;
    }
    return;
}
//L-------R
//  l---mid---r
void modify(int index,int L,int R,int l,int r,int def) {
    if(l >= L && r <= R) {
        lazy[index] += def;
        s[index] += def*(r-l+1);
        return;
    }

    int mid = (l + r)/2;
    down(index,l,r);
    if(mid >= L) modify(index<<1, L, R, l, mid, def); //tag
    if(mid < R) modify(index<<1|1, L, R, mid+1, r, def);
    up(index);
    return;
}

ll query(int index,int L,int R,int l,int r) {
    if(l >= L && r <= R) return s[index];


    int mid = (l + r)/2;
    ll ans = 0;
    down(index,l,r);
    if(mid >= L) ans += query(index<<1, L, R, l, mid); //tag
    if(mid < R)  ans += query(index<<1|1, L, R, mid+1, r);
    return ans;
}

int main() {
    freopen("in","r",stdin);
    int i,n,m,beg,end;
    char op;
    int tmp;
    while(scanf("%d%d",&n,&m) == 2) {
        memset(lazy,0,sizeof(lazy));
        memset(s,0,sizeof(s));
        for(i=1; i<=n; i++) {
            scanf("%d",&tmp);
            modify(1,i,i,1,n,tmp);
        }
        while(m--) {
            scanf(" %c",&op);
            if(op == 'C') {
                scanf("%d%d%d",&beg,&end,&tmp);
                modify(1,beg,end,1,n,tmp);
            } else {
                scanf("%d%d",&beg,&end);
                printf("%lld\n",query(1,beg,end,1,n));
            }
        }
    }
    return 0;
}


