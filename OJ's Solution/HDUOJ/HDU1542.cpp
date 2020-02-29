//AC
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define prt(x) printf(#x " = %.2lf\n",x);
using namespace std;

#define lc(x) x<<1
#define rc(x) x<<1|1
const int maxn = 300;

double sgy[maxn];
struct RECTANGLE {
    double x,y1,y2;
    int flag;
    void init(double a,double b1,double b2,int flag1) { x = a; y1 = b1; y2 = b2; flag = flag1;}
} rec[maxn << 3];

struct TREENODE {
    double l,r,sum;
    int lazy;
    TREENODE() {lazy=0;}
    void init(double l1,double r1,double sum1,int lazy1) { l=l1; r=r1; sum=sum1; lazy=lazy1; }
} tn[maxn<<3];

bool cmp(RECTANGLE a,RECTANGLE b) {
    return a.x < b.x;
}

void buildTree(int l,int r,int idx) {
    if(r-l >1) {
        int mid = (l+r)>>1;
        tn[idx].init(sgy[l],sgy[r],0,0);
        buildTree(l,mid,lc(idx));
        buildTree(mid,r,rc(idx));
    } else {
        tn[idx].init(sgy[l],sgy[r],0,0);
    }
    return;
}

void pushUp(int idx) {
    TREENODE& now = tn[idx];
    if(now.lazy > 0) now.sum = now.r - now.l;
    else now.sum = tn[lc(idx)].sum + tn[rc(idx)].sum;
}

void update(double tarL,double tarR,int idx,int add) {
    TREENODE& now = tn[idx];
    if(now.l == tarL && now.r == tarR) {
        now.lazy += add;
        pushUp(idx);
        return;
    } 
    if(tn[lc(idx)].r > tarL) update(tarL,min(tn[lc(idx)].r,tarR),lc(idx),add);
    if(tn[rc(idx)].l < tarR) update(max(tn[rc(idx)].l,tarL),tarR,rc(idx),add);
    pushUp(idx);
}

int main() {
    int n,size,temp = 0;
    double x1,x2,y1,y2,res;
    while(~scanf("%d",&n)) {
        if(!n) break;
        //init
        memset(rec,0,sizeof(rec));
        memset(tn,0,sizeof(tn));
        res = 0;

        for(int i=0; i<n; i++) {
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            rec[i].init(x1,y1,y2,1);
            rec[i+n].init(x2,y1,y2,-1);
            sgy[i] = y1;
            sgy[i+n] = y2;
        }

        //离散化
        sort(sgy,sgy+n*2);
        size = unique(sgy,sgy+n*2) - sgy;

        //建树
        buildTree(0,size-1,1);

        //求解
        sort(rec,rec+2*n,cmp);
        int end = 2*n;
        double perX = rec[0].x;
        for(int i=0; i<end; i++) {
            RECTANGLE& now = rec[i];
            if(i) res += (now.x-perX)*tn[1].sum;
            update(now.y1,now.y2,1,now.flag);
            perX = now.x;
        }
        printf("Test case #%d\nTotal explored area: %.2lf\n\n",++temp,res);
    }
    return 0;
}
