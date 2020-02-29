#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;

const int Emaxn = 2e5+100,Hmaxn = 5e3+100;
struct EDGE {
    int to,next,w;
};
struct ND {
    int to,w;
    ND(int b,int ww) :to(b),w(ww) {}
    ND() {}
};
bool operator < (const ND &a,const ND &b) {
    return a.w > b.w;
}

EDGE edge[Emaxn<<2];
int head[Hmaxn],cnt;
bool vis[Hmaxn];
priority_queue<ND> List;

void addEdge(int a,int b,int ww) {
    cnt++;
    edge[cnt].to = b;
    edge[cnt].w = ww;
    edge[cnt].next = head[a];
    head[a] = cnt;
}

int Prim(void) {
    int out = 0;
    ND now(1,0);
    List.push(now);
    while(!List.empty()) {
        now = List.top();
        List.pop();
        if(vis[now.to]) continue;
        out += now.w;
        vis[now.to] = 1;
        for(int i=head[now.to]; i != -1; i=edge[i].next) {
            if(!vis[edge[i].to]) List.push(ND(edge[i].to,edge[i].w));
        }
    }
    return out;
}

int main() {
    int n,m;
    int f,t,ww;
    scanf("%d%d",&n,&m);
    cnt = 0;
    for(int i=0; i<=n; i++) head[i] = -1;
    while(m--) {
        scanf("%d%d%d",&f,&t,&ww);
        vis[f] = vis[t] = 1;
        addEdge(f,t,ww);
        addEdge(t,f,ww);
    }
    for(int i=1; i<=n; i++) {
        if(vis[i] == 0) {
            printf("orz\n");
            return 0;
        }
        vis[i] = 0;
    }
    printf("%d\n",Prim());
    return 0;
}
