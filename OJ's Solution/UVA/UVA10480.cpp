#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;

#define INF 0x3f3f3f3f
const int maxn = 67;
bool vv[maxn];
set<int> setS;

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

	void findSetInit() { memset(vis,0,sizeof(vis)); }
	void findSetS(int now) {
		vis[now] = 1;
		for(int i=0; i<G[now].size(); i++) {
			if(!vis[edges[G[now][i]].to] && edges[G[now][i]].cap > edges[G[now][i]].flow) findSetS(edges[G[now][i]].to);
		}
	}
};

int main() {
	Dinic dinic;
	int n,m,ans;
	int u,v,tmp;
	while(~scanf("%d%d",&n,&m)) {
		setS.clear();
		if(!(n||m)) break;
		dinic.init(n+3);
		for(int i=0; i<m; i++) {
			scanf("%d%d%d",&u,&v,&tmp);
			dinic.AddEdge(u,v,tmp);
			dinic.AddEdge(v,u,tmp);
		}
		dinic.Maxflow(1,2);
		dinic.findSetInit();
		dinic.findSetS(1);
		// for(int i=1; i<=n; i++) {
		// 	cout << i << "=" << dinic.vis[i] << endl;
		// }

		vv[1] = 1;
		for(int now=1; now <= n; now++) {
			if(dinic.vis[now]) {
				memset(vv,0,sizeof(vv));
				for(int i=0; i<dinic.G[now].size(); i++) {
					Edge& e = dinic.edges[dinic.G[now][i]];
					if(!dinic.vis[e.to] && !vv[e.to])  {
						vv[e.to] = 1;
						printf("%d %d\n",now,e.to);
					}
				}
			}
		}
		putchar('\n');
	}
	return 0;
}
