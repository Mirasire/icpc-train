#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

#define INF 0x3f3f3f3f
const int maxn = 3e3+100;
typedef long long int ll;

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
	Dinic dinic;
	ll n,cnt = 0,sum=0,k,m;
	ll s = 0,t = maxn-20,tmp;
	ll c1,c2;
	scanf("%lld",&n);
	//s->node
	for(int i=1; i<=n; i++) {
		scanf("%lld",&tmp);
		sum += tmp;
		dinic.AddEdge(s,i,tmp);
	}
	//node->t
	for(int i=1; i<=n; i++) {
		scanf("%lld",&tmp);
		sum += tmp;
		dinic.AddEdge(i,t,tmp);
	}
	scanf("%lld",&k);
	for(int i=1,j=n+1; i<=k; i++,j+=2) {
		//j,j+1
		scanf("%lld%lld%lld",&m,&c1,&c2);
		sum += c1;
		sum += c2;
		dinic.AddEdge(s,j,c1);
		dinic.AddEdge(j+1,t,c2);
		for(int k=0; k<m; k++) {
			scanf("%lld",&tmp);
			dinic.AddEdge(j,tmp,INF);
			dinic.AddEdge(tmp,j+1,INF);
		}
	}
	printf("%lld\n",sum - dinic.Maxflow(s,t));
	return 0;
}

