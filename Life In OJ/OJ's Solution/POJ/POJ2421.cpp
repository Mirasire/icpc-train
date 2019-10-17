#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <limits.h>
#include <queue>
using namespace std;

const int maxn = 1e2+10,INF = INT_MAX;
typedef long long int ll;
ll map[maxn][maxn],mini[maxn];
bool vis[maxn];
int n;

void init(int n) {
    for(int i=0; i<=n; i++) {
        mini[i] = INF;
        vis[i] = 0;
        for(int j=0; j<=n; j++) {
            if(j==i) map[i][j] = 0;
            else map[i][j] = INF;
        }
    }
    mini[1] = 0;
}

ll Prim() {
    ll out = 0;
    while(1) {
        int v = -1;
        for(int i=1; i<=n; i++) {
            if(!vis[i] && (v==-1 || mini[i] < mini[v])) v = i;
        }
        if(v==-1) break;
        out += mini[v];
        vis[v] = 1;
        for(int i=1; i<=n; i++) mini[i] = min(mini[i],map[v][i]);
    }
    return out;
}

int main() {
    int tp;
    scanf("%d",&n);
    init(n);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            scanf("%d",&tp);
            map[i][j] = tp;
        }
    }
    int Q,a,b;
    scanf("%d",&Q);
    while(Q--) {
        scanf("%d%d",&a,&b);
        map[a][b] = map[b][a] = 0;
    }
    printf("%lld",Prim());
}
