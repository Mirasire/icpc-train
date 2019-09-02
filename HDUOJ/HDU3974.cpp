#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 5e4+100;
vector<int> f[maxn];
int l[maxn<<2],r[maxn<<2],ll[maxn],rr[maxn];
int colo[maxn<<2],cnt;
bool vis[maxn];

void build(int i,int ld,int rd) {
    l[i] = ld,r[i] = rd;
    colo[i] = -1;
    if(ld == rd) return;
    build(i<<1,ld,(ld+rd)>>1);
    build(i<<1|1,((ld+rd)>>1) + 1,rd);
}

void down_colo(int i) {
    if(colo[i] != -1) {
        colo[i<<1] = colo[i<<1|1] = colo[i];
        colo[i] = -1;
    }
    return;
}

void modify(int i,int L,int R,int def) {
    if(l[i] >= L && r[i] <= R) {
        colo[i] = def;
        return;
    }
    int mid = (l[i] + r[i]) >> 1;
    down_colo(i);
    if(mid >= L) modify(i<<1,L,R,def);
    if(mid < R) modify(i<<1|1,L,R,def);
}

int query(int i,int L) {
    if(l[i] == L && r[i] == L) {
        return colo[i];
    }
    int mid = (l[i] + r[i]) >> 1;
    down_colo(i);
    if(mid >= L) return query(i<<1,L);
    else return query(i<<1|1,L);
}

void dfs(int now) {
    vis[now] = 1;
    cnt++;
    ll[now] = cnt;
    int end = f[now].size();
    for(int i=0; i<end; i++) dfs(f[now][i]);
    rr[now] = cnt;
    return;
}

int main () {
    int t,n,i,tmp;
    int u,v,m,def,kase = 0;
    char op;
    scanf("%d",&t);
    while(t--) {
        printf("Case #%d:\n",++kase);
        cnt = 0;
        scanf("%d",&n);
        for(i=0; i<=n; i++) {
            f[i].clear();
            vis[i] = 0;
        }
        for(i=1; i<n; i++) {
            scanf("%d%d",&u,&v);
            f[v].push_back(u);
        }
        for(i=1; i<=n; i++) 
            if(!f[i].empty() && !vis[i]) {
                dfs(i);
            }

        build(1,0,cnt);
        scanf("%d",&m);
        while(m--) {
            scanf(" %c",&op);
            if(op == 'C') {
                scanf("%d",&i);
                printf("%d\n",query(1,ll[i]));
            } else {
                scanf("%d%d",&i,&def);
                modify(1,ll[i],rr[i],def);
            }
        }
    }
    return 0;
}
