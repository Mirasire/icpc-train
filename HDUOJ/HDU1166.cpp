#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;


const int maxn = 5e4+20;
int s[maxn << 2],lazy[maxn << 2];

void up(int index) {
    s[index] = s[index<<1|1] + s[(index<<1)+2];
}
void down(int index,int l,int r) {
    int mid = (l+r)/2;
    lazy[index*2+1] = lazy[index];
    lazy[index*2+2] = lazy[index];
    s[index*2 + 1] += lazy[index]*(mid - l + 1);
    s[index*2 + 2] += lazy[index]*(r - mid);
    lazy[index] = 0;
}

// Target_index: L-------R 
// finding_index:  l----mid------r
int query(int index,int L,int R,int l,int r) {
    if(l >= L && r <= R) return s[index];
    int mid = (l+r)/2,ans = 0;
    down(index,l,r);
    if(mid >= L) ans += query(index*2+1,L,R,l,mid);
    if(mid < R) ans += query(index*2+2,L,R,mid+1,r);
    return ans;
}

void modify(int index,int L,int R,int l,int r,int plus) {
    if(l >= L && r <= R) {
        s[index] += (r-l+1) * plus;
        lazy[index] += plus;
        return;
    }
    int mid = (l+r)/2;
    down(index,l,r);
    if(mid >= L) modify(index*2+1,L,R,l,mid,plus);
    if(mid < R) modify(index*2+2,L,R,mid+1,r,plus);
    up(index);
}

int main() {
    freopen("in","r",stdin);
    int l,r,p,tmp,T,kase = 0;
    string op;
    scanf("%d",&T);
    while(T--) {
        int n;
        memset(s,0,sizeof(s));
        memset(lazy,0,sizeof(lazy));
        printf("Case %d:\n",++kase);
        scanf("%d",&n);
        for(int i=0; i<n; i++) {
            scanf("%d",&tmp);
            lazy[i] = 0;
            modify(0,i+1,i+1,1,n,tmp);
        }
        while(1) {
            cin >> op;
            if(op == "Query") {
                scanf("%d%d",&l,&r);
                printf("%d\n",query(0,l,r,1,n));
            }
            else if(op == "End") {
                break;
            }
            else {
                scanf("%d%d",&l,&p);
                if(op == "Sub") p = -p;
                modify(0,l,l,1,n,p);
            }
        }
    }
    return 0;
}
