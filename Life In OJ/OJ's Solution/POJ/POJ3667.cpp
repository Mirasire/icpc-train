#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define ls(x) x<<1
#define rs(x) x<<1|1
#define prt(x) printf(#x " = %d\n",x)
const int maxn = 5e4+10;
struct NDD {
    int l,r;
    int lazy,pr,bk,mxl;
};
NDD nd[maxn<<2];
bool flag;
int out;

void build(int i,int ld,int rd) {
    nd[i].l = ld;
    nd[i].r = rd;
    nd[i].mxl = nd[i].bk = nd[i].pr = rd - ld + 1;
    nd[i].lazy = 1;
    if(ld == rd) return;
    int mid = (ld + rd) >> 1;
    build(i<<1,ld,mid);
    build(i<<1|1,mid+1,rd);
}

void down_lazy(int i) {
    if(nd[i].lazy != -1) {
        nd[ls(i)].lazy = nd[rs(i)].lazy = nd[i].lazy;
        nd[rs(i)].bk = nd[rs(i)].mxl = nd[rs(i)].pr = nd[i].lazy * (nd[rs(i)].r - nd[rs(i)].l + 1);
        nd[ls(i)].bk = nd[ls(i)].mxl = nd[ls(i)].pr = nd[i].lazy * (nd[ls(i)].r - nd[ls(i)].l + 1);
        nd[i].lazy = -1;
    }
}

// 1-all empty 0-all full -1-wuhoho
void up(int i) {
    if(nd[ls(i)].lazy == nd[rs(i)].lazy) nd[i].lazy = nd[ls(i)].lazy;
    else nd[i].lazy = -1;

    nd[i].pr = nd[ls(i)].pr;
    nd[i].bk = nd[rs(i)].bk;

    nd[i].mxl = max(nd[ls(i)].mxl,nd[rs(i)].mxl);
    nd[i].mxl = max(nd[i].mxl,nd[ls(i)].bk + nd[rs(i)].pr);

    //cout << i <<"'s mxl = " << nd[i].mxl << endl;

    if(nd[ls(i)].lazy==1) nd[i].pr += nd[rs(i)].pr;
    if(nd[rs(i)].lazy==1) nd[i].bk += nd[ls(i)].bk;
}

void modify(int i,int ld,int rd,int def) {
    //cout << ld << " " << rd << endl;
    if(nd[i].l == ld && nd[i].r <= rd) {
        nd[i].lazy = def;
        nd[i].pr = nd[i].bk = nd[i].mxl = def*(rd-ld+1);
        return;
    }
    int mid = (nd[i].l+nd[i].r) >>1;
    //down_lazy(i);
    //prt(ld);
    //prt(rd);
    //prt(nd[i].l);
    //prt(nd[i].r);
    //prt(mid);
    down_lazy(i);
    if(ld >= mid+1) modify(rs(i),ld,rd,def);
    else if(rd <= mid) modify(ls(i),ld,rd,def);
    else {
        modify(ls(i),ld,mid,def);
        modify(rs(i),mid+1,rd,def);
    }
    up(i);
}

//TODO
void query(int i,int k) {
    if(flag || !nd[i].lazy) return;
    if(nd[i].pr >= k) {
        flag = 1;
        out = nd[i].l;
        modify(1,nd[i].l,nd[i].l + k - 1,0);
    } else if(nd[ls(i)].mxl >= k) {
        query(ls(i),k);
    } else if(nd[ls(i)].bk + nd[rs(i)].pr >= k) {
        int beg = nd[ls(i)].r - nd[ls(i)].bk + 1;
        int ed = beg + k - 1;
        modify(1,beg,ed,0);
        out = beg;
        flag = 1;
    } else {
        query(rs(i),k);
    }
    return;
}

int main() {
    int n,m;
    int op;
    int k,l,r;
    scanf("%d%d",&n,&m);
    build(1,1,n);
    while(m--) {
        scanf("%d",&op);
        //prt(nd[1].bk);
        if(op == 1) {
            scanf("%d",&k);
            if(nd[1].mxl < k) {
                printf("0\n");
                continue;
            }
            flag = 0;
            query(1,k);
            printf("%d\n",out);
        } else {
            scanf("%d%d",&l,&r);
            modify(1,l,l+r-1,1);
        }
    }
    return 0;
}
