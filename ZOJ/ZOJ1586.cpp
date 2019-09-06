#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <limits.h>
using namespace std;

typedef long long int ll;
ll cnt = 0;
const int Hmaxn = 1e3+100;
struct Edge{
    int from,to,w;
};
Edge edge[Hmaxn*Hmaxn];
int head[Hmaxn];
int f[Hmaxn],n;
bool cmp(const Edge& a,const Edge& b) {
    return a.w < b.w;
}

int find(int a) {
    int root = a,tp;
    while(f[root] != root) root = f[root];
    while(a != root) {
        tp = f[a];
        f[a] = root;
        a = tp;
    }
    return root;
}

bool unite(int a,int b) {
    if(find(a) == find(b)) return 0;
    f[find(a)] = find(b);
    return 1;
}

ll Kruskal() {
    ll out = 0;
    sort(edge,edge+cnt,cmp);
    for(int i=0; i<cnt; i++) {
        if(unite(edge[i].to,edge[i].from)) {
            out += edge[i].w;
        }
    }
    return out;
}

int main() {
    int T;
    ll basic,tmp;
    scanf("%d",&T);
    while(T--) {
        basic = cnt = 0;
        scanf("%d",&n);
        for(int i=0; i<n; i++) f[i] = i;
        for(int i=0; i<n; i++) scanf("%d",head+i);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                scanf("%lld",&tmp);
                if(i != j) {
                    edge[cnt].from = i;
                    edge[cnt].to = j;
                    edge[cnt].w = tmp+head[i]+head[j];
                    cnt++;
                }
            }
        }
        printf("%lld\n",basic + Kruskal());
    }
}
