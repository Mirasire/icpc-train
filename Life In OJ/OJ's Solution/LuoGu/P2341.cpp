//AC
#include <bits/stdc++.h>
using namespace std;

const int Vmaxn = 1e4+100,Emaxn = 5e4+100;
int n,m;

//for graph; Init to -1!!
int head[Vmaxn],cnt;

//for Tarjan; Init nscc = idx = 0;
int low[Vmaxn],dnf[Vmaxn],scc[Vmaxn],stk[Vmaxn],nscc,idx;
int num[Vmaxn],newHeadNum[Vmaxn];

struct EDGE {
    int to,nxt;
} e[Emaxn];

void addEdge(int u,int v) {
    cnt++;
    e[cnt].to = v; e[cnt].nxt = head[u]; head[u]=cnt; 
}

void tarjan(int u) {
    dnf[u] = low[u] = ++cnt;
    stk[++idx] = u;
    for(int i=head[u]; i!=-1; i=e[i].nxt) {
        int v = e[i].to;
        if(!dnf[v]) {
            tarjan(v);
            low[u] = min(low[v],low[u]);
        } else if (!scc[v]) low[u] = min(dnf[v],low[u]);
    }

    //count the SCC
    if(low[u]==dnf[u]) {
        nscc++;
        while(idx>=0) {
            int now = stk[idx--];
            num[nscc]++;
            scc[now] = nscc;
            if(now==u) break;
        }
    }
}

int main() {
    //Init
    int n,m,u,v;
    scanf("%d%d",&n,&m);
    nscc = idx = cnt = 0;
    for(int i=0; i<=n; i++) head[i] = -1;
    for(int i=0; i<m; i++) {
        scanf("%d%d",&u,&v);
        addEdge(u,v);
    }

    cnt=0;
    for(int i=1; i<=n; i++) {
        if(!dnf[i]) tarjan(i);
    }

    for(int i=1; i<=n; i++) {
        int key = scc[i];
        for(int j=head[i]; j!=-1; j=e[j].nxt) {
            int v = e[j].to;
            if(scc[i] != scc[v]) newHeadNum[key]++;
        }
    }
    int ans = 0;
    for(int i=1; i<=nscc; i++) {
        if(!newHeadNum[i]) {
            if(!ans) ans = num[i];
            else {
                ans = 0;
                break;
            }
        }
    }
    printf("%d\n",ans);

    return 0;
}