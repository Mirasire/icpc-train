#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <limits.h>
using namespace std;

const int maxn = 70,INF = INT_MAX;
int map[maxn][maxn],mini[maxn],n;
bool vis[maxn];

int Prim() {
    int out = 0;
    while(1) {
        int v  = -1;
        for(int i=1; i<=n; i++) {
            if(!vis[i] && (v==-1 || mini[i] < mini[v])) v = i;
        }
        if(v==-1) break;
        out += mini[v];
        vis[v]  = 1;
        for(int i=1; i<=n; i++) mini[i] = min(mini[i],map[v][i]);
    }
    return out;
}

void init() {
    for(int i=0; i<60; i++) {
        vis[i] = 0;
        mini[i] = INF;
        for(int j=0; j<60; j++) {
            if(i!=j) map[i][j] = INF;
            else map[i][j] = 0;
        }
    }
    mini[1] = 0;
}

int main() {
    int m;
    int a,b,ww;
    while(scanf("%d%d",&n,&m) == 2) {
        init();
        while(m--) {
            scanf("%d%d%d",&a,&b,&ww);
            if(ww < map[a][b]) map[a][b] = map[b][a] = ww;
        }
        printf("%d\n",Prim());
    }
}
