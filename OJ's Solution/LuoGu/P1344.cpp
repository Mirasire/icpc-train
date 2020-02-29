//割边数量为将图的容量改为1跑一遍dinic
//Wrong Slution on question 2
/*
 *	   Input
		9 12
		1 2 10
		1 3 10
		1 4 10
		2 3 15
		4 3 15
		3 5 100
		5 6 10
		5 7 10
		5 8 10
		6 9 10
		7 9 10
		8 9 10
 *	   Output
 *	   30 2
 *
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

/*for debug:
	cout << "\nedge: " << i << " --> "  << e.to;
*/

#define INF 0x3f3f3f3f
const int maxn = 42;

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
	Dinic dinic,dinic2;
	int n,m;
	int a,b,c;
	scanf("%d%d",&n,&m);
	int s = 1, t = n;
	while(m--) {
		scanf("%d%d%d",&a,&b,&c);
		dinic.AddEdge(a,b,c);
		dinic2.AddEdge(a,b,1);
	}
	printf("%d %d",dinic.Maxflow(s,t),dinic2.Maxflow(s,t));
	return 0;
}
