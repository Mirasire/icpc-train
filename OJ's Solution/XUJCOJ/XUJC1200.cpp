#include <iostream>
#include <cstdio>
#include <algorithm>
#include <limits.h>
using namespace std;

const int maxn = 1e5+100;
struct VERTEX {
    int sum,small,big;
    VERTEX(): sum(0),small(0),big(0) {};
    VERTEX operator += (const VERTEX & other) {
        sum += other.sum;
        big = max(other.big,big);
        small = min(other.small,small);
    }
};
VERTEX s[maxn<<2|1];
int lazy[maxn<<2|1];

void up(int index) {
    s[index].sum = s[index*2+1].sum + s[index*2+2].sum;
    s[index].small = min(s[index*2+1].small,s[index*2+2].small);
    s[index].big = max(s[index*2+1].big,s[index*2+2].big);
}

void down_lazy(int index,int l,int r) {
    if(lazy[index]) {
        int mid = (l+r)/2;
        lazy[index*2 + 1] += lazy[index];
        lazy[index*2 + 2] += lazy[index];
        s[index*2+1].sum += lazy[index]*(mid-l+1);
        s[index*2+2].sum += lazy[index]*(r-mid);
        s[index*2+1].small += lazy[index];
        s[index*2+2].small += lazy[index];
        s[index*2+1].big += lazy[index];
        s[index*2+2].big += lazy[index];
        lazy[index] = 0;
    }
    return;
}

void modify(int L,int R,int l,int r,int index,int key) {
    if(l > R || r < L) return;
    if(l >= L && r <= R) {
        lazy[index] += key;
        s[index].sum += (r - l + 1) * key;
        s[index].big += key;
        s[index].small += key;
        return;
    }
    down_lazy(index,l,r);
    int middle = (l+r)/2;
    if(middle >= L) {
        modify(L,R,l,middle,index*2+1,key);
    }
    if(middle < R) {
        modify(L,R,middle+1,r,index*2+2,key);
    }
    up(index);
}

// L-R is target
// l-r is NowPosition
VERTEX query(int L,int R,int l,int r,int index) {
    if(l >= L && r <= R) return s[index];
    int middle  = (l+r)/2;
    VERTEX ans;
    ans.small = INT_MAX;
    ans.big = INT_MIN;
    down_lazy(index,l,r);
    if(middle >= L) {
        ans += query(L,R,l,middle,index*2+1);
    }
    if(middle < R) {
        ans += query(L,R,middle+1,r,index*2+2);
    }
    return ans;
}

int main() {
    freopen("in","r",stdin);
    int n,m,l,r,key;
    char op;
    VERTEX tmp;
    scanf("%d%d",&n,&m);
    while(m--) {
        //for(int i=1; i<=n; i++)
        //    cout << i << ": " << query(i,i,1,n,0).small << " |";
        scanf(" %c",&op);
        if (op == 'C') {
            scanf("%d%d%d",&l,&r,&key);
            modify(l,r,1,n,0,key);
        }
        else if (op == 'X') {
            scanf("%d%d",&l,&r);
            tmp = query(l,r,1,n,0);
            modify(l,r,1,n,0,tmp.big);
        }
        else if (op == 'N') {
            scanf("%d%d",&l,&r);
            tmp = query(l,r,1,n,0);
            modify(l,r,1,n,0,-tmp.small);
        }
        else{
            scanf("%d%d",&l,&r);
            tmp = query(l,r,1,n,0);
            printf("%d\n",tmp.sum);
        }
    }
    return 0;
}
