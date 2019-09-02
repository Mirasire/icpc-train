#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 1e5+100;
struct node {
    double l,r;
    double sum;
};
node tn[maxn<<3];
double ls[maxn<<3];
int lazy[maxn<<3];

struct node1 {
    int x,y1,y2;
    int flag;
};
node tr[maxn<<2];

void putup(int i) {
    if(lazy[i] > 0) tn[i].sum  = tn[i].r - tn[i].l;
    else tn[i].sum = tn[i<<1].sum + tn[i<<1|1].sum;
}

void build(int i,int l,int r) {
    tn[i].l = ls[l];
    tn[i].r = ls[r];
    tn[i].sum = 0;
    if(r-l == 1) return;
    build(i<<1,l,(l+r) >> 1);
    build(i<<1|1,(l+r)>>1,(l+r) >> 1);
    putup(i);
}

//y1------y2
void update(int i,double y1,double y2,int flag) {
    if(tn[i].l == y1 && tn[i].r == y2) {
        lazy[i] += flag;
        putup(i);
        return;
    }
    if(tn[i<<1].r > y1) update(i<<1,y1,min(tn[i<<1].r,y2),flag);
    if(tn[i<<1|1].l < y2) update(i<<1|1,max(tn[i<<1|1].r,y1),y2,flag);
    putup(i);
}
