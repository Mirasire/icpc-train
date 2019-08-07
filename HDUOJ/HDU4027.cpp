//optimization s[index] == l-r+1 return
//Ac
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;
const ll maxn = 1e5+100;
ll real[maxn<<2],s[maxn<<2],out,tmp;

void up(int index) { 
    s[index] = s[index<<1] + s[index<<1|1];
}

void build(int index,int l,int r) {
    if(l==r) {
        scanf("%lld",&tmp);
        s[index] =  tmp;
        return;
    }
    int mid = (l+r)>>1;
    build(index<<1,l,mid);
    build(index<<1|1,mid+1,r);
    up(index);
}

void modify(int index,int L,int R,int l,int r) {
    if(l==r) {
        if(s[index] == 1) return;
        s[index] = (ll)sqrt(s[index]);
        return;
    } else if(l>=L && r<=R && s[index] == (r-l+1)) return; //cut
    int mid = (l+r)>>1;
    if(mid >= L) modify(index<<1,L,R,l,mid);
    if(mid < R) modify(index<<1|1,L,R,mid+1,r);
    up(index);
}

void query(int index,int L,int R,int l,int r) {
    if(l>=L && r<=R) {
        out += s[index];
        return;
    }
    int mid = (l+r)>>1;
    if(mid >= L) query(index<<1,L,R,l,mid);
    if(mid < R) query(index<<1|1,L,R,mid+1,r);
}

void init() {
    memset(s,0,sizeof(s));
    out = 0;
}

int main() {
    int n,i,L,R,op,x,y,kase=0,m;
    while(scanf("%d",&n) != EOF) {
        init();
        printf("Case #%d:\n",++kase);
        build(1,1,n);
        scanf("%d",&m);
        while(m--) {
            scanf("%d%d%d",&op,&x,&y);
            L = min(x,y);
            R = max(x,y);
            if(op) {
                out = 0;
                query(1,L,R,1,n);
                printf("%lld\n",out);
            } else modify(1,L,R,1,n);
        }
        printf("\n");
    }
    return 0;
}
