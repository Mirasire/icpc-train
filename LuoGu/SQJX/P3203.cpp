#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 2e5+100;
int l[maxn],r[maxn],belong[maxn],num,block;
int cost[maxn],out[maxn];
int n,m,k[maxn],op,def,idx,ans;

void build(int n) {
    block = sqrt(n);
    num = n/block; if(n%block) num++;
    for(int i=1; i<=num; i++)
        l[i] = (i-1) * block + 1,r[i] = i*block;
    r[num] = n;
    for(int i=1; i<=n; i++)
        belong[i] = (i-1)/block + 1;
}

void update(int left,int right) {
    for(int i=right; i>=left; i--) {
        if(i+k[i] > r[belong[i]] ) {
            cost[i] = 1;
            out[i] = i+k[i];
        } else {
            cost[i] = cost[i+k[i]] + 1;
            out[i] = out[i+k[i]];
        }
    }
}

int main() {
    //freopen("in","r",stdin);
    scanf("%d",&n);
    for(int i=1; i<=n; i++) scanf("%d",k+i);
    build(n);
    update(1,n);
    scanf("%d",&m);
    while(m--) {
        scanf("%d%d",&op,&idx);
        idx++;
        if(op == 2) {
            scanf("%d",&def);
            k[idx] = def;
            update(l[belong[idx]],r[belong[idx]]);
        } else {
            ans = 0;
            while(idx <= n && belong[idx] <= num) {
                ans += cost[idx];
                idx = out[idx];
            }
            printf("%d\n",ans);
        }
    }
    //return 0;
}
