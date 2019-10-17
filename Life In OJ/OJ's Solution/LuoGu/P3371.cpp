#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int Emaxn = 5e5+100,Hmaxn = 1e4+100;
struct EDAGE {
    int to,next,w;
};

struct DISTANCE {
    int cost,i;
};

bool const operator < (const DISTANCE &a,const DISTANCE &b) {
    return  a.cost >= b.cost;
}

EDAGE edage[Emaxn];
int head[Hmaxn];
int dist[Hmaxn];
bool vis[Hmaxn];
int cnt;
priority_queue<DISTANCE> dis;

inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}

//a->b
void addEdage(int a,int b,int weight) {
    cnt++;
    edage[cnt].to = b;
    edage[cnt].w = weight;
    edage[cnt].next = head[a];
    head[a] = cnt;
    return;
}

void dijkstra(int st) {
    int index;
    DISTANCE now,next;
    now.cost = 0;
    now.i = st;
    dis.push(now);
    while(!dis.empty()) {
        now = dis.top();
        dis.pop();
        if(vis[now.i]) continue;
        vis[now.i] = 1;
        for(index = head[now.i]; index != -1; index = edage[index].next) {
            next.cost = now.cost + edage[index].w;
            next.i = edage[index].to;
            if( (next.cost < dist[next.i] && dist[next.i] != -1) || dist[next.i] == -1) {
                dist[edage[index].to] = next.cost;
                dis.push(next);
            }
        }
    }
    return;
}

int main() {
    int n,m,s;
    int a,b,ww;
    /*
    n = read();
    m = read();
    s = read();
    */
    scanf("%d%d%d",&n,&m,&s);
    cnt = 0;
    for(int i=1; i<=n; i++) {
        dist[i] = head[i] = -1;
        vis[i] = 0;
    }
    //memset(dist,-1,sizeof(dist));
    //memset(head,-1,sizeof(head));
    while(m--) {
        /*
        a = read();
        b = read();
        ww = read();
        */
        scanf("%d%d%d",&a,&b,&ww);
        addEdage(a,b,ww);
    }
    dist[s] = 0;
    dijkstra(s);
    for(int k=1; k<=n; k++) {
        if(dist[k] == -1) printf("2147483647 ");
        else printf("%d ",dist[k]);
    }
    return 0;
}
