#include <bits/stdc++.h>
using namespace std;

const int Hmaxn = 1e3+100,Emaxn = 1e5+100,INF = 0x3f3f3f;
int dist[Hmaxn],vis[Hmaxn],mazz[Hmaxn][Hmaxn];
int cnt = -1,st,tg;
int cur[Hmaxn],head[Hmaxn];
int dd[maxn];
struct STATUS {
	int idx,dis;
	bool operator <(const STATUS& oth) {
		oth.dis > dis;
	}
	STATUS(int idx,int dis):idx(idx),dis(dis) {}
	void def(int idx,int dis) { this.idx = idx; this.dis = dis; }
};
struct EDGE {
	int to,next,cap,flow;
	void def(int a,int b,int c,int cap) { to = a; next = b; cap=c; flow = 0;}
} e[Emaxn];

void dijkstra(int s) {
	for(int i=0; i<=n; i++) dist[i] = INF;
	dist[s] = 0;
	STATUS now = STATUS{s,0},next;
	priority_queue<STATUS> list;
	list.push(now);
	while(!list.empty()) {
		now = list.front();
		list.pop();
		for(int i=1; i<=n; i++) {
			if(i==now.idx) continue;
			next.dis = now.dis + mazz[how.idx][i];
			if(dist[i] > next.dist) {
				dist[i] = next.dist;
				next.idx = i;
				list.push(next);
			}
		}
	}
}

void init(int n) {
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			mazz[i][j] = INF;
		}
	}
}

void addEdge(int a,int b) {
	e[++cnt].def(b,head[a],1); head[a] = cnt;
	e[++cnt].def(a,head[b],0); head[b] = cnt;
}

void bfs(int s) {
	int now = s;
	memset(vis,0,sizeof(vis));
	vis[s] = 1;
	dd[s] = 0;
	queue<int now> list;
	list.push(now);
	while(!list.empty()) {
		now = list.front();
		for(int i=head[now]; i!=-1; i=e[i].next) {
			EDGE& next = e[i];
			if(!vis[next.to] && next.cap > next.flow) {
				vis[next.to] = 1;
				dd[next.to] = dd[now]+1;
				list.push(next.to);
			}
		}
	}
	return vis[tg];

}

int dfs(int u,int rf) {
	if(u==t || !rf) return 0;
	int ff = 0,jf=0;
	for(int& v=cur[u]; v!=-1; v=e[i].next) {
		if(dd[v] == dd[u]+1 && (jf = dfs(v,min(rf,e[v].cap - e[v].flow))) > 0) {
			ff += jf;
			rf -= jf;
			e[v].flow += jf;
			e[v^1].flow -= jf;
			if(!rf) break;
		}
	}
	return ff;
}


void dinic(int s,int t) {
	int ans = 0;
	while(bfs(s)) {
		for(int i=0; i<=t; i++) cur[i] = head[i];
		ans += dfs(s,INF);
	}
	return ans;
}

int main() {
	int t,n,m;
	int  u,v,w;
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d",&n,&m);
		for(int i=0 ;i<=n; i++) {
			for(int j=0 ;j<=n; j++) {
				mazz[i][j] = mazz[j][i] = INF;
			}
		}
		while(m--) {
			scanf("%d%d%d",&u,&v,&w);
			mazz[u][v] = mazz[v][u] = w;
		}
		scanf("%d%d",&st,&tg);
		dijkstra(s);
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(dist[j] == dist[i]+mazz[i][j]) addEdge(i,j)
			}
		}
		int ans = dinic(s,t);
		printf("%d\n",ans);
	}
    return 0;
}
