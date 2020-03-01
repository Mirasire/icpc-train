#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << " = " << x << endl;

const int maxn = 1e5+100;
struct NODE {
    int l,r,fa;
    int val,d;
} llt[maxn];
#define ls(x) llt[x].l
#define rs(x) llt[x].r

int merge(int x,int y) {
    if(!x||!y) return  x|y;
    if(llt[x].val>llt[y].val || (llt[x].val==llt[y].val && x>y)) swap(x,y);
    rs(x)=merge(rs(x),y);
    if(llt[ls(x)].d<llt[rs(x)].d) swap(ls(x),rs(x));
    llt[x].d = llt[rs(x)].d+1;
    return x;
}

void pop(int x) {
    llt[x].val = -1;
    llt[ls(x)].fa = llt[rs(x)].fa = llt[x].fa = merge(ls(x),rs(x));
}

int find(int u) {
    int a=u,tp;
    while(llt[u].fa!=u) u=llt[u].fa; //寻找自身的时候肯定可以找到自环。
    while(llt[a].fa!=u) {  //但是假设是提前确定目标可能会在前一步停止。
        tp=llt[a].fa; 
        llt[a].fa=u; 
        a=tp; 
    }
    return u;
}

int main() {
    std::ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    llt[0].d=0;
    for(int i=1; i<=n; i++) llt[i].fa=i,cin >> llt[i].val;
    int op,x,y,fx,fy;
    while(m--) {
        cin >> op;
        if(op==1) {
            cin >> x >> y;
            if(llt[x].val==-1||llt[y].val==-1) continue;
            fx = find(x); fy = find(y);
            if(fx!=fy) llt[fx].fa = llt[fy].fa = merge(fx,fy);
        } else {
            cin >> x;
            if(llt[x].val==-1) {
                cout << -1 << endl;
            } else {
                fx=find(x);
                cout << llt[fx].val << endl;
                pop(fx);
            }
        }
    }
    return 0;
}
