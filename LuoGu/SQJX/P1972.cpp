//Pass 8A turn 
//pass 9A turn on O2
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <iostream>
#include <cmath>
using namespace std;

const int max_id = 1e6+100;
bool vis[max_id];
int id[max_id],block,ans;
int cnt[max_id];
int anss[max_id];

struct TYPE{
    int num,l,r;
};

TYPE si[max_id];

bool cmp(TYPE &a, TYPE &b) {
    return (a.l/block)^(b.l/block)? a.l<b.l : (((a.l/block)&1) ? a.r<b.r : a.r>b.r);
}

void add(int index) {
    if(cnt[id[index]]==0) ans++;
    cnt[id[index]]++;
}

void del(int index) {
    cnt[id[index]]--;
    if(cnt[id[index]]==0) ans--;
}

int main() {
    //freopen("in","r",stdin);
    int n,m,l,r,i;
    int tl,tr;
    scanf("%d",&n);
    for(i=1; i<=n; i++) scanf("%d",id+i);
    scanf("%d",&m);

    block = n/sqrt(m*2/3);
    for(i=1; i<=m; i++) {
        scanf("%d%d",&si[i].l,&si[i].r);
        si[i].num = i;
    }
    sort(si+1,si+1+m,cmp);

    l = 1,r=0;
    ans = 0;
    for(i=1; i<=m; i++) {
        tl = si[i].l;
        tr = si[i].r;
        while(l < tl) del(l++);
        while(l > tl) add(--l);
        while(r < tr) add(++r);
        while(r > tr) del(r--);
        anss[si[i].num] = ans;
    }
    for(i=1; i<=m; i++) printf("%d\n",anss[i]);
    return 0;
}

