//AC
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
using namespace std;

#define INF 0x3f3f3f3f
const int maxn = 2e3;
char str[210];

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

void slove(int &n,int &f,int &d) {
	Dinic dinic;
	int v,tmp,cc;
	int s = 0,t = 1e3+600;
	//food n+1 to n+f
	//drink n+f+1 to n+f+d
	//people = 1 to n
	cc = n+f+d;
	//cut
	for(int i=1; i<=n; i++) dinic.AddEdge(i,i+cc,1);
	//s->food
	tmp = n;
	for(int i=1; i<=f; i++) {
		scanf("%d",&v);
		dinic.AddEdge(s,tmp+i,v);
	}
	//drink->t
	tmp = n+f;
	for(int i=1; i<=d; i++) {
		scanf("%d",&v);
		dinic.AddEdge(tmp+i,t,v);
	}
	//food->to people
	tmp = n;
	for(int i=1; i<=n; i++) {
		scanf(" %s",str);
		for(int j=0; j<f; j++) {
			if(str[j] == 'Y') dinic.AddEdge(tmp+j+1,i,INF);
		}
	}
	//to->drink people
	tmp = n+f;
	for(int i=1; i<=n; i++) {
		scanf(" %s",str);
		for(int j=0; j<d; j++) {
			if(str[j] == 'Y') dinic.AddEdge(i+cc,tmp+j+1,INF);
		}
	}
	cout << dinic.Maxflow(s,t) << endl;
	return;
}

int main() {
	int n,f,d;
	while(~scanf("%d%d%d",&n,&f,&d)) slove(n,f,d);
	return 0;
}
