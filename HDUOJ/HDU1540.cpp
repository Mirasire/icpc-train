//ACed
#include <iostream>
#include <string.h>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <cmath>
#define prt(x) printf(#x " = %d\n",x)
using namespace std;

const int maxn = 5e4+10;
int per[maxn << 2],rev[maxn << 2],sum[maxn << 2];
int out;
stack<int> reb;

void up(int index,int l,int r) {
    per[index] = per[index<<1];
    rev[index] = rev[index<<1|1];
    sum[index] = max(max(sum[index<<1],sum[index<<1|1]),rev[index<<1]+per[index<<1|1]);
    int mid = (l+r)/2;
    if(mid - l + 1 == sum[index<<1])  per[index] += per[index<<1|1];
    if(r - mid == sum[index<<1|1])  rev[index] += rev[index<<1];
}

void build(int index,int l,int r) {
    if(l==r) {
        per[index] = rev[index] = sum[index] = 1;
        return;
    }
    int mid = (l+r)/2;
    if(l!=r){
        build(index<<1,l,mid);
        build(index<<1|1,mid+1,r);
    }
    up(index,l,r);
}

void modify(int index,int L,int R,int l,int r,int def) {
    if(l>=L && r<=R) {
        per[index] = rev[index] = sum[index] = def;
        return;
    }
    int mid = (r+l)/2;
    if(mid >= L) modify(index<<1,L,R,l,mid,def);
    else modify(index<<1|1,L,R,mid+1,r,def);
    up(index,l,r);
}

//problem habbened
void query(int index,int L,int R,int l,int r) {
    if(sum[index] == r-l+1 || sum[index]==0 || l == r) { //:== debug for unlimited times
        out += sum[index];
        return;
    }
    int mid  = (l+r) >> 1;
    if(L <= mid) {
        if(L >= mid - rev[index<<1] + 1) {
            out += rev[index<<1] + per[index<<1|1];
            return;
        } else query(index<<1,L,R,l,mid);
    } else {
        if( L <= mid + per[index<<1|1]) {  //WA: 6
            out+= rev[index<<1] + per[index<<1|1];
            return;
        } else query(index<<1|1,L,R,mid+1,r);
    }
}

int main() {
    int n,m;
    int L;
    char op;
    while(scanf("%d%d",&n,&m)==2) {
        while(!reb.empty()) reb.pop();
        memset(per,0,sizeof(per));
        memset(rev,0,sizeof(rev));
        memset(sum,0,sizeof(sum));
        build(1,1,n);
        while(m--) {
            scanf(" %c",&op);
            if(op == 'R') {
                L = reb.top();
                reb.pop();
                modify(1,L,L,1,n,1);
            }
            else {
                scanf("%d",&L);
                if(op == 'D') {
                    reb.push(L);
                    modify(1,L,L,1,n,0);
                } else {
                    out = 0;
                    query(1,L,L,1,n);
                    printf("%d\n",out);
                }
            }
        }
    }
    return 0;
}
