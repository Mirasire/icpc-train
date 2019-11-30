#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define debug(x) printf(#x "= %d\n",x)

//define the const
const int MaxCol = 120,MaxRow = 120;
const int maxn = 2e4+100,INF = 0x3f3f3f3f;

// 0 targe for vertial | 1 targe for horizontal
int grid[MaxCol][MaxRow][2],idx[MaxCol][MaxRow]; 
bool isWhite[MaxCol][MaxRow];
char assit[20];

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
	int n,m,s,t;
	Dinic dinic;
	while(~scanf("%d%d",&n,&m)) {
		//Init
		int vCnt=0,hCnt=0,cnt=0;
		int subs = 0;

		//It's for array Init
		for(int i=0; i<n; i++) {
			for(int j=0; j<m ;j++) {
				isWhite[i][j] = 0;
				idx[i][j] = grid[i][j][0] = grid[i][j][1] = 0;
			}
		}

		//Read in
		int as=0,bs=0;
		for(int i=0; i<n; i++) {
			for(int j=0; j<m ;j++) {
				scanf(" %s",assit);
				if(assit[3] == '.') {
					idx[i][j] = ++cnt;
					isWhite[i][j] = 1;
				} else {
					//Do It For vertial
					isWhite[i][j] = 0;
					if(assit[0] != 'X') {
						grid[i][j][0] = 100*(assit[0]-'0') + 10*(assit[1]-'0') + assit[2]-'0';
						vCnt++;
					} else {
						grid[i][j][0] = -1;
					}

					//Do It For horizontal
					if(assit[4] != 'X') {
						grid[i][j][1] = 100*(assit[4]-'0') + 10*(assit[5]-'0') + assit[6]-'0';
						hCnt++;
					} else {
						grid[i][j][1] = -1;
					}
				}
			}
		}

		//set the s and the t;
		s = 0;
		t = vCnt + hCnt + cnt +12;
		vCnt = hCnt = 0;

		//preprocessing with the graph && build the graph

		// do for the horizontal
		for(int i=0; i<n; i++) {
			subs = 0;
			for(int j=m-1; j>=0; j--) {
				if(isWhite[i][j]) subs++;
				else if(grid[i][j][1] != -1) {
					grid[i][j][1] -= subs;
					subs = 0;
					dinic.AddEdge(s,cnt+(++hCnt),grid[i][j][1]);
					printf("for horizontal #%d , %d# = %d\n",i,j,grid[i][j][1]);
					//start to build the graph
					for(int k=j; k<m&&isWhite[i][k]; k++) dinic.AddEdge(cnt+hCnt,idx[i][k],8);
				}
			}
		}

		//do for the vertial
		for(int i=0; i<m; i++) {
			subs = 0;
			for(int j=n-1; j>=0; j--) {
				if(isWhite[j][i]) subs++;
				else if(grid[j][i][0] != -1){
					grid[j][i][0] -= subs;
					subs = 0;
					dinic.AddEdge(cnt+hCnt+(++vCnt),t,grid[j][i][0]);
					printf("for vertial #%d , %d# = %d\n",j,i,grid[j][i][0]);
					//start to build the graph
					for(int k=j; k<n&&isWhite[k][i]; k++) dinic.AddEdge(idx[k][i],cnt+hCnt+vCnt,8);
				}
			}
		}

		//Let's dance~
		debug(dinic.Maxflow(s,t));

		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(j) putchar(' ');
				if(isWhite[i][j]) {
					//out puts the ans
					putchar('1');
					//printf("%d",dinic.edges[dinic.G[idx[i][j]][0]].flow+1);
				} else putchar('_');
			}
			putchar('\n');
		}
	}
	return 0;
}
