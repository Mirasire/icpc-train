//AC Version
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define INF 0x3f3f3f3f
const int maxn = 70*70+50;
int val[90];
int in[90][12];
int out[90][12];
int res[maxn][4];

struct Edge {
	int from, to, cap, flow;
	Edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
};

struct Dinic {
	int n, m, s, t;
	vector<Edge> edges;
	vector<int> G[maxn];
	int d[maxn], cur[maxn];
	bool vis[maxn];

	void init(int n) {
		for (int i = 0; i < n; i++) G[i].clear();
		edges.clear();
	}

	void AddEdge(int from, int to, int cap) {
		edges.push_back(Edge(from, to, cap, 0));
		edges.push_back(Edge(to, from, 0, 0));
		m = edges.size();
		G[from].push_back(m - 2);
		G[to].push_back(m - 1);
	}

	bool BFS() {
		memset(vis, 0, sizeof(vis));
		queue<int> Q;
		Q.push(s);
		d[s] = 0;
		vis[s] = 1;
		while (!Q.empty()) {
			int x = Q.front();
			Q.pop();
			for (int i = 0; i < G[x].size(); i++) {
				Edge& e = edges[G[x][i]];
				if (!vis[e.to] && e.cap > e.flow) {
					vis[e.to] = 1;
					d[e.to] = d[x] + 1;
					Q.push(e.to);
				}
			}
		}
		return vis[t];
	}

	int DFS(int x, int a) {
		if (x == t || a == 0) return a;
		int flow = 0, f;
		for (int& i = cur[x]; i < G[x].size(); i++) {
			Edge& e = edges[G[x][i]];
			if (d[x] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap - e.flow))) > 0) {
				e.flow += f;
				edges[G[x][i] ^ 1].flow -= f;
				flow += f;
				a -= f;
				if (a == 0) break;
			}
		}
		return flow;
	}

	int Maxflow(int s, int t) {
		this->s = s;
		this->t = t;
		int flow = 0;
		while (BFS()) {
			memset(cur, 0, sizeof(cur));
			flow += DFS(s, INF);
		}
		return flow;
	}
};

int main() {
	int p,n;
	Dinic dinic;
	while(~scanf("%d%d",&p,&n)) {
		dinic.init(n*2+5);
		for(int i=1; i<=n; i++) {
			scanf("%d",&val[i]);
			for(int j=0; j<p; j++) scanf("%d",&in[i][j]);
			for(int j=0; j<p; j++) scanf("%d",&out[i][j]);
		}

		//============建图============
		int s = 0, t=n<<1|1;
		for(int i=1; i<=n; i++) {
			bool flag = 1;
			for(int j=0; j<p; j++)
				if(in[i][j]==1) {
					flag=0;
					break;
				}
			if(flag) dinic.AddEdge(s,i,INF);
		}

		//============拆点============
		for(int i=1; i<=n; i++) dinic.AddEdge(i,i+n,val[i]);

		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(i==j) continue;
				bool flag = 1;
				for(int k=0; k<p; k++)
					if(out[i][k] != in[j][k] && in[j][k] != 2) {
						flag = 0;
						break;
					}
				if(flag) dinic.AddEdge(i+n,j,INF);
			}
		}

		for(int i=1; i<=n; i++) {
			bool flag = 1;
			for(int j=0; j<p; j++)
				if(out[i][j]!=1) {
					flag=0;
					break;
				}
			if(flag) dinic.AddEdge(i+n,t,INF);
		}
		//============建图END============

		
		//============跑Dinic求最大流============
		int mff = dinic.Maxflow(s,t);
		int tt = 0;
		//============寻找路径============
		for(int i=n+1; i<t; i++) {
			int end = dinic.G[i].size();
			for(int j=0; j<end; j++) {
				Edge e = dinic.edges[dinic.G[i][j]];
				if(e.cap && e.flow > 0 && e.to <=n ) {
					res[tt][2] = e.flow;
					res[tt][0] = i-n;
					res[tt++][1] = e.to;
				}
			}
		}

		printf("%d %d\n",mff,tt);
		//============路径输出============
		for(int i=0; i<tt; i++) {
			printf("%d %d %d\n",res[i][0],res[i][1],res[i][2]);
		}
	}
	return 0;
}
