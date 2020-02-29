#include <iostream>
#include <cstring>
#include <limits.h>
#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;

const int maxn = 5e4+10;
struct TY {
    int minn,maxx;
    TY(): maxx(INT_MIN),minn(INT_MAX) {};
};
TY cow[maxn << 2];
int omax,omin;

void up(int index) {
    cow[index].maxx = max(cow[index<<1].maxx,cow[index<<1|1].maxx);
    cow[index].minn = min(cow[index<<1].minn,cow[index<<1|1].minn);
}

void modify(int index,int idx,int l,int r,int def) {
    if(l==r && l == idx) {
        cow[index].minn = def;
        cow[index].maxx = def;
        return;
    }
    int mid = (l+r)/2;
    if(mid >= idx) modify(index<<1,idx,l,mid,def);
    if(mid < idx) modify(index<<1|1,idx,mid+1,r,def);
    up(index);
}

void query(int index,int L,int R,int l,int r) {
    if(l>=L && r<=R) {
        omin = min(omin,cow[index].minn); 
        omax = max(omax,cow[index].maxx);
        return;
    }
    int mid = (l+r)/2;
    if(mid >= L) query(index<<1,L,R,l,mid);
    if(mid < R) query(index<<1|1,L,R,mid+1,r);
}

int main() {
    int L,R;
    int n,m,tmp;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++) {
        scanf("%d",&tmp);
        modify(1,i,1,n,tmp);
    }
    while(m--) {
        omax = INT_MIN;
        omin = INT_MAX;
        scanf("%d%d",&L,&R);
        query(1,L,R,1,n);
        printf("%d\n",omax-omin);
    }
    return 0;
}

