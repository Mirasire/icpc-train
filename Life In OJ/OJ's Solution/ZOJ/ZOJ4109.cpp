#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <vector>
using namespace std;

const int maxn = 1e6+100;
int f[maxn],n,cnt;
bool vis[maxn];
vector<int> nxt[maxn];

int fi(int id){
    return id==f[id]? id : f[id] = fi(f[id]);
}

void unite(int a,int b) {
    int r_a  = fi(a);
    int r_b  = fi(b);
    f[max(r_a,r_b)] = min(r_a,r_b);
    return;
}

void bfs(int id){
    int now,i,sz;
    priority_queue<int,vector<int>,greater<int> > List;
    List.push(id);
    while(!List.empty()){
        now = List.top();
        List.pop();
        if(now != 0){
            cnt++;
            printf("%d%c",now," \n"[cnt==n]);
        }
        sz = nxt[now].size();
        for(i=0; i<sz; i++) {
            if(!vis[nxt[now][i]]){
                vis[nxt[now][i]]  = 1;
                List.push(nxt[now][i]);
            }
        }
    }
    return;
}

int main() {
    freopen("in","r",stdin);
    int m,a,b,k,ans;
    scanf("%d",&m);
    while(m--) {
        ans = cnt = 0;
        scanf("%d%d",&n,&k);
        for(int i=0; i<=n; i++) {
            f[i] = i;
            nxt[i].clear();
            vis[i] = 0;
        }
        while(k--) {
            scanf("%d%d",&a,&b);
            unite(a,b);
            nxt[a].push_back(b);
            nxt[b].push_back(a);
        }
        for(int i=1; i<=n; i++) {
            if(f[i] == i) {
                ans++;
                nxt[0].push_back(i);
            }
        }
        printf("%d\n",ans);
        bfs(0);
    }
    return 0;
}

