//WA-reson if(sta != 1) down_ns(i);
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
#define ls(i) i<<1
#define rs(i) i<<1|1
using namespace std;

struct ND {
    int l,r;
    int pr,bk,mlx,lazy;
    void init(int ld,int rd) {
        l = ld,r = rd;
        pr = bk = mlx = r-l +1;
        lazy = 1;
    }
    void rebiuld(int nla) {
        pr = bk = mlx = nla*(r-l +1);
        lazy = nla;
    }
    int getmid(void) { return (l+r)>>1; }
};

const int maxn = 1e5+100;
ND ds[maxn<<2],ns[maxn<<2];
int t,n,k,st;
string op;

void build(int i,int ld,int rd) {
    ds[i].init(ld,rd);
    ns[i].init(ld,rd);
    if(ld == rd) return;
    int mid = (ld+rd) >> 1;
    build(ls(i),ld,mid);
    build(rs(i),mid+1,rd);
}

void down_ns(int i) {
    if(ns[i].lazy != -1) {
        ns[ls(i)].rebiuld(ns[i].lazy);
        ns[rs(i)].rebiuld(ns[i].lazy);
        ns[i].lazy = -1;
    }
}

void down_ds(int i) {
    if(ds[i].lazy != -1) {
        ds[ls(i)].rebiuld(ds[i].lazy);
        ds[rs(i)].rebiuld(ds[i].lazy);
        ds[i].lazy = -1;
    }
}

void up(int i) {
    if(ds[ls(i)].lazy == ds[rs(i)].lazy) ds[i].lazy = ds[rs(i)].lazy;
    else ds[i].lazy = -1;
    ds[i].pr = ds[ls(i)].pr;
    ds[i].bk = ds[rs(i)].bk;
    ds[i].mlx = max(ds[ls(i)].mlx,ds[rs(i)].mlx);
    ds[i].mlx = max(ds[i].mlx,ds[rs(i)].pr + ds[ls(i)].bk);
    if(ds[ls(i)].lazy == 1) ds[i].pr += ds[rs(i)].pr;
    if(ds[rs(i)].lazy == 1) ds[i].bk += ds[ls(i)].bk;

    if(ns[ls(i)].lazy == ns[rs(i)].lazy) ns[i].lazy = ns[rs(i)].lazy;
    else ns[i].lazy = -1;
    ns[i].pr = ns[ls(i)].pr;
    ns[i].bk = ns[rs(i)].bk;
    ns[i].mlx = max(ns[ls(i)].mlx,ns[rs(i)].mlx);
    ns[i].mlx = max(ns[i].mlx,ns[rs(i)].pr + ns[ls(i)].bk);
    if(ns[ls(i)].lazy == 1) ns[i].pr += ns[rs(i)].pr;
    if(ns[rs(i)].lazy == 1) ns[i].bk += ns[ls(i)].bk;
}

//1-xd 2-ns 3-cl
void modify(int i,int ld,int rd,int def,int sta) {
    if(ns[i].l == ld && ns[i].r == rd) {
        ds[i].rebiuld(def);
        if(sta != 1) ns[i].rebiuld(def);
        return;
    }
    int mid = ns[i].getmid();
    down_ds(i);
    //WA-reson if(sta != 1) down_ns(i);
    down_ns(i); 	

    if(ld >= mid + 1) modify(rs(i),ld,rd,def,sta);
    else if(rd <= mid) modify(ls(i),ld,rd,def,sta);
    else {
        modify(ls(i),ld,mid,def,sta);
        modify(rs(i),mid+1,rd,def,sta);
    }
    up(i);
}

void query_ds(int i,int k) {
    down_ds(i);
    if(ds[i].pr >= k) {
        st = ds[i].l;
        modify(1,ds[i].l,ds[i].l+k-1,0,1);
    } else if(ds[ls(i)].mlx >= k) {
        query_ds(ls(i),k);
    } else if(ds[ls(i)].bk + ds[rs(i)].pr >= k) {
        int beg = ds[ls(i)].r - ds[ls(i)].bk + 1;
        int ed = beg + k -1;
        st = beg;
        modify(1,beg,ed,0,1);
    } else {
        query_ds(rs(i),k);
    }
    return;
}


void query_ns(int i,int k) {
    down_ns(i);
    if(ns[i].pr >= k) {
        st = ns[i].l;
        modify(1,ns[i].l,ns[i].l+k-1,0,2);
    } else if(ns[ls(i)].mlx >= k) {
        query_ns(ls(i),k);
    } else if(ns[ls(i)].bk + ns[rs(i)].pr >= k) {
        int beg = ns[ls(i)].r - ns[ls(i)].bk + 1;
        int ed = beg + k -1;
        st = beg;
        modify(1,beg,ed,0,2);
    } else {
        query_ns(rs(i),k);
    }
    return;
}

int main () {
    int CASE;
    int beg,ed;
    scanf("%d",&CASE);
    for(int i=1; i<=CASE; i++) {
        printf("Case %d:\n",i);
        scanf("%d%d",&n,&t);
        build(1,1,n);
        while(t--) {
            cin >> op;
            //cout << ns[1].mlx << " " << ds[1].mlx << endl;
            if(op == "STUDY!!") {
                scanf("%d%d",&beg,&ed);
                modify(1,beg,ed,1,3);
                printf("I am the hope of chinese chengxuyuan!!\n");
            } else if(op == "DS") {
                scanf("%d",&k);
                if(k > ds[1].mlx) {
                    printf("fly with yourself\n");
                    continue;
                }
                query_ds(1,k);
                printf("%d,let's fly\n",st);
            } else {
                scanf("%d",&k);
                if(k > ns[1].mlx) {
                    printf("wait for me\n");
                    continue;
                }
                if(ds[1].mlx >= k) {
                    //cout << 1 << endl;
                    query_ds(1,k);
                    modify(1,st,st+k-1,0,2);
                } else {
                    //cout << 2 << endl;
                    query_ns(1,k);
                }
                printf("%d,don't put my gezi\n",st);
            }
        }
    }
    return 0;
}
