//拆点+建图+挺麻烦的裸题
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define maxn 25
#define INF 0x3f3f3f3f

struct PILLER {
	int x,y;
	PILLER(int x,int y):x(x),y(y) {}
	PILLER() {}
};
vector<PILLER> pList;
char liz[maxn][maxn],liz[maxn][maxn];
int idx[maxn][maxn],cap[maxn][maxn];


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
		vis[s] = 2;
		while (!Q.empty()) {
			int x = Q.front();
			Q.pop();
			for (int i = 0; i < G[x].size(); i++) {
				Edge& e = edges[G[x][i]];
				if (!vis[e.to] && e.cap > e.flow) {
					vis[e.to] = 1;
					d[e.to] = d[x] + 1;
					q.push(e.to);
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
	int T,mini,dis;
	int s,t,psize;
	int n,m,d,cnt;
	scanf("%d",&T);
	while(T--) {
		m = cnt = 0;
		scanf("%d%d",&n,&d);
		//cin the pillers
		for(int i=0; i<n; i++) {
			scanf(" %s",pil[i]);
			if(!m) m = strlen(pil[i]);
			for(int j=0; j<m; j++) {
				if(pil[i][j] != '0') {
					idx[i][j] = ++idx;
					cap[i][j] = pil[i][j] - '0';
					pList.push_back((i,j));
				}
			}
		}

		//set the s and t && psize
		s = 0;
		t = cnt<<1|1;
        dinic.init(t+1);
		psize = pList.size();

		//cin the lizards
		for(int i=0; i<n; i++) {
			scanf(" %s",liz[i]);
			for(int j=0; j<m; j++) {
				if(liz[i][j] == 'L') {
					dinic.AddEdge(s,idx[i][j],cap[i][j],1);
				}
			}
		}

		//cut point
		for(int i=0; i<psize; i++) {
			PILLER& now = pList[i];
			dinic.AddEdge(idx[now.x][now.y],idx[now.x][now.y]+cnt,cap[i][j]);
			mini = min(min(now.x+1,n-now.x),min(now.y+1,m-now.y));
			if(mini <= d) dinic.AddEdge(idx[now.x][now.y]+cnt,t,INF);
		}

		//make them connect
		for(int i=0; i<psize; i++) {
			PILLER& now = pList[i];
			for(int j=i+1; j<psize; j++) {
				PILLER& to = pList[j];
				dis = abs(now.x-to.x) + abs(now.y-to.y);
				if(dis <= d) {
					dinic.AddEdge(idx[now.x][now.y]+cnt,idx[to.x][to.y],INF);
					dinic.AddEdge(idx[tt.x][tt.y]+cnt,idx[now.x][now.y],INF);
				}
			}
		}
        printf("%d\n",dinic.Maxflow(s,t));
	}
    return 0;
}
