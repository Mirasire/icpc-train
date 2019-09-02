#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

struct EDGE {
    int from,to,w;
    void in(int a,int b,int ww) {
        from  = a;
        to = b;
        w = ww;
    }

};
bool const operator < (const EDGE &a,const EDGE &b) {
    return a.w > b.w;
}

const int Emaxn = 2e5+100,Hmaxn = 5e3+100;
EDGE edge[Emaxn];
int f[Hmaxn];
bool vis[Hmaxn];
priority_queue<EDGE> List;

int find_root(int a) {
    int root = a;
    int son = root;
    int tmp;
    while(root != f[root]) root = f[root];
    while(son != root) {
        tmp = f[son];
        f[son] = root;
        son = tmp;
    }
    return root;
}

bool unit(int a,int b) {
    int fa = find_root(a);
    int fb = find_root(b);
    if(fa!=fb) {
        f[fa] = fb;
        return 1;
    } else 
        return 0;
}

int kruskal(void) {
    int rst = 0;
    EDGE now;
    while(!List.empty()) {
        now = List.top();
        List.pop();
        if(unit(now.from,now.to))  rst += now.w;
    }
    return rst;
}

int main() {
    int n,m;
    int a,b,ww;
    EDGE now;
    scanf("%d%d",&n,&m);
    for(int i=0; i<=n; i++) {
        vis[i] = 0;
        f[i] = i;
    }
    while(m--) {
        scanf("%d%d%d",&a,&b,&ww);
        now.in(a,b,ww);
        vis[a] = vis[b] = 1;
        List.push(now);
    } 
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            printf("orz\n");
            return 0;
        }
    }
    printf("%d\n",kruskal());
    return 0;
}
