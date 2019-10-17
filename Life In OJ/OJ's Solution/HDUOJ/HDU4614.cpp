#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define prt(x) printf(#x " = %d\n",x)
using namespace std;

const int maxn = 5e4+10;
int lazy[maxn<<2],s[maxn<<2];
int per[maxn<<2],ed[maxn<<2];
int flower,edx;
long long int sum;
int t,n,m,op,A,F;
int pp;

void up(int i) {
    s[i] = s[i<<1] + s[i<<1|1];
    per[i] = min(per[i<<1],per[i<<1|1]);
    ed[i] = max(ed[i<<1],ed[i<<1|1]);
}

void build(int i,int l,int r) {
    per[i] = l;
    ed[i] = r;
    s[i] = 0;
    lazy[i] = -1;
    if(l == r) return;
    build(i<<1,l,(l+r) >> 1);
    build(i<<1|1,((l+r) >> 1) + 1,r);
}

void down_lazy(int i,int l,int r) {
    if(lazy[i] != -1) {
        int mid = (l+r) >> 1;
        if(lazy[i] == 0) {
            per[i<<1] = l;
            per[i<<1|1] = mid+1;
            ed[i<<1] = mid;
            ed[i<<1|1] = r;
        } else {
            per[i<<1] = per[i<<1|1] = n-1;
            ed[i<<1] = ed[i<<1|1] = 0;
        }
        lazy[i<<1] = lazy[i<<1|1] = lazy[i];
        s[i<<1] = lazy[i] * (mid - l + 1);
        s[i<<1|1] = lazy[i] * (r - mid);
        lazy[i] = -1;
    }
}

void modify(int i,int L,int R,int l,int r) {
    int fill = r-l+1;
    if(flower == 0 || fill == s[i]) return;
    if(l>= L && r<=R && fill - s[i] <= flower) {
        flower -= fill- s[i];
        s[i] = fill; 
        pp = min(pp,per[i]);
        per[i] = n-1;
        lazy[i] = 1;
        edx = ed[i];
        ed[i] = 0;
        return;
    }
    int mid = (l+r) >> 1;
    down_lazy(i,l,r);
    if(mid >= L) modify(i<<1,L,R,l,mid);
    if(mid < R ) modify(i<<1|1,L,R,mid+1,r);
    up(i);
}

void query(int i,int L,int R,int l,int r) {
    if(l>= L && r<=R) {
        sum += s[i];
        per[i] = l;
        ed[i] = r;
        lazy[i] = s[i] = 0;
        return;
    }
    int mid = (l+r) >> 1;
    down_lazy(i,l,r);
    if(mid >= L) query(i<<1,L,R,l,mid);
    if(mid < R ) query(i<<1|1,L,R,mid+1,r);
    up(i);
}

int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&n,&m);
        build(1,0,n-1);
        while(m--) {
            scanf("%d%d%d",&op,&A,&F);
            if(op == 1) {
                flower = F;
                edx = -1;
                pp = n-1;
                modify(1,A,n-1,0,n-1);
                if(edx != -1) printf("%d %d\n",pp,edx);
                else printf("Can not put any one.\n");
            } else {
                sum = 0;
                query(1,A,F,0,n-1);
                printf("%lld\n",sum);
            }
        }
        printf("\n");
    }
    return 0;
}
