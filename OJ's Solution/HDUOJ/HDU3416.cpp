//AC
#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
const int maxn = 1e3+100;

//===For Dijkstra====
struct DEdge {
	int to,nxt,w;
	DEdge() {}
	void def(int a,int b,int wi) { to=a; nxt=b; w=wi; }
} de[200200];
struct STATUS {
	int idx,td;
	STATUS() {}
	STATUS(int idx,int td):idx(idx),td(td) {}
	bool operator< (const STATUS& oth) const { return td > oth.td; }
};
int head[maxn],dist[maxn],dcnt;

void DaddEdge(int u,int v,int w) {
	de[++dcnt].def(u,head[v],w); head[v] = dcnt;
}

void dijkstra(int s) {
	dist[s] = 0;
	STATUS now = {s,0};
	priority_queue<STATUS> list;
	list.push(now);
	while(!list.empty()) {
		now = list.top();
		list.pop();
		if(dist[now.idx] < now.td) continue;
		for(int i=head[now.idx]; i!=-1; i=de[i].nxt) {
			DEdge& v = de[i];
			if(v.w+now.td < dist[v.to]) {
				dist[v.to] = now.td + v.w;
				list.push({v.to,dist[v.to]});
			}
		}
	}
}



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
	int T;
	int u,v,iw;
	int n,m,s,t;
	Dinic dinic;
	scanf("%d",&T);
	while(T--) {
		//Init
		scanf("%d%d",&n,&m);
		dcnt = 0;
		for(int i=0; i<=n; i++) {
			dist[i] = INF;
			head[i] = -1;
		}
		dinic.init(n+1);

		for(int i=0; i<m; i++) {
			scanf("%d%d%d",&u,&v,&iw);
			DaddEdge(v,u,iw);
		}
		scanf("%d%d",&s,&t);
		//cout << "Input Ok\n";
		dijkstra(s);
		//cout << "Dijkstra\n";
		for(int i=1; i<=n; i++) {
			for(int j=head[i]; j!=-1; j=de[j].nxt) {
				if(dist[de[j].to] == dist[i]+de[j].w) dinic.AddEdge(i,de[j].to,1);
			}
		}
		printf("%d\n",dinic.Maxflow(s,t));
	}
	return 0;
}
