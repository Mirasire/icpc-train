#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;

const int maxn = 2e5+20;
int m[maxn*4],lazy[maxn*4];

void up(int index) {
    m[index] = max(m[index*2+1],m[index*2+2]);
}

void down(int index,int l,int r) {
    m[index*2 + 1] += lazy[index];
    m[index*2 + 2] += lazy[index];
    lazy[index*2 + 1] = lazy[index*2 + 2] = lazy[index];
    lazy[index] = 0;
}

// L------------R
//      l-----mid------r
void modify(int index,int L,int R,int l,int r,int plus) {
    if(l >= L && r <= R) {
        m[index] = plus;
        return;
    }
    int mid = (l+r) / 2;
    down(index,l,r);
    if(mid < R) modify(index*2+2,L,R,mid+1,r,plus);
    if(mid >= L) modify(index*2+1,L,R,l,mid,plus);
    up(index);
}

int query(int index,int L,int R,int l,int r) {
    if(l >= L && r <= R) return m[index];
    int mid = (l+r) / 2,ans = 0;
    down(index,l,r);
    if(mid >= L) ans = query(index*2+1,L,R,l,mid);
    if(mid < R) ans = max(ans,query(index*2+2,L,R,mid+1,r));
    return ans;
}

int main() {
    freopen("in","r",stdin);
    int i,n,t,tmp,l,r;
    char op;
    while(scanf("%d%d",&n,&t) == 2) {
        memset(lazy,0,sizeof(lazy));
        memset(m,0,sizeof(m));
        for(i=0; i<n; i++) {
            scanf("%d",&tmp);
            modify(0,i+1,i+1,1,n,tmp);
        }
        while(t--) { 
            scanf(" %c",&op);
            if(op == 'Q') {
                //cout << 1 << endl;
                scanf("%d%d",&l,&r);
                printf("%d\n",query(0,l,r,1,n));
            } else {
                //cout << 2 << endl;
                scanf("%d%d",&l,&tmp);
                modify(0,l,l,1,n,tmp);
            }
        }
    }
    return 0;
}

