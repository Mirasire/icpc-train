//Pass 8A turn 
//pass 9A turn on O2
//Pass All use O2 && 快读读取
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

int read(void) {
    char x;
    while((x = getchar()) > '9' || x <'0');
    int u = x-'0';
    while((x=getchar()) <= '9' && x >= '0') u = (u<<3) + (u<<1) + x - '0';
    return u;
}
int buf[105];
inline void write(int i) {  
    int p = 0;  
    if(i == 0) p++;  
    else while(i) {  
        buf[p++] = i % 10;  
        i /= 10;  
    }  
    for(int j = p-1; j >= 0; j--) putchar('0' + buf[j]);  
}


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
    n = read();
    for(i=1; i<=n; i++) id[i] = read();
    m = read();

    block = n/sqrt(m*2/3);
    for(i=1; i<=m; i++) {
        si[i].l = read();
        si[i].r = read();
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
    for(i=1; i<=m; i++) {
        write(anss[i]);
        putchar('\n');
    }
    return 0;
}

