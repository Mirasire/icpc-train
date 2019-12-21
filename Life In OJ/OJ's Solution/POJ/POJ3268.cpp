//O(n*nlogn) 求多源最短路中的最长路
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>
using namespace std;

const int maxn = 1e3+100,MM = 1e5+100,INF = 0x3f3f3f3f;
int dist[maxn][maxn],head[maxn];
bool vis[maxn];

struct EDGE {
	int to,nxt,t;
	void def(int a,int b,int c) { to=a; nxt=b; t=c; }
} e[MM];
int cnt = 0;

void addEdge(int a,int b,int t) {
	e[++cnt].def(b,head[a],t); head[a]=cnt;
}

struct STATUS {
	int idx,val;
	STATUS() {}
	STATUS(int idx,int val):idx(idx),val(val) {}
	bool operator<(const STATUS& oth) const { return val > oth.val; }
};

void dijkstra(int s,int n) {
	for(int i=0; i<=n; i++) vis[i]=0;
	STATUS now(s,0);
	dist[s][s] = 0;
	priority_queue<STATUS> list;
	list.push(now);
	while(!list.empty()) {
		now = list.top();
		list.pop();
		if(vis[now.idx]) continue;
		vis[now.idx] = 1;
		dist[s][now.idx] = now.val;
		for(int i=head[now.idx]; i!=-1; i=e[i].nxt) 
			if(now.val+e[i].t < dist[s][e[i].to])			//-700ms
				list.push({e[i].to,now.val+e[i].t});
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	int n,m,x;
	scanf("%d%d%d",&n,&m,&x);
	//init
	for(int i=0; i<=n; i++) {
		head[i] = -1;
		for(int j=0; j<=m; j++) {
			dist[i][j] = INF;
		}
	}
	
	int u,v,t;
	while(m--) {
		scanf("%d%d%d",&u,&v,&t);
		addEdge(u,v,t);
	}
	for(int i=1; i<=n; i++) dijkstra(i,n);
	int ans = 0;
	for(int i=1; i<=n; i++) 
			ans = max(dist[i][x] + dist[x][i],ans);
	printf("%d\n",ans);
	return 0;
}
