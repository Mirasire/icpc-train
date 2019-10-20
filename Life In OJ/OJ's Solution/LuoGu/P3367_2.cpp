#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

const int NODEMAX = 1e4+100;
const int EDGEMAX = 2e5+100;
const int inf = 0x3f3f3f3f;
int n,m;

struct EDGE {
	int to,next,flow,cap,rev;
	EDGE(){}
	void init(int to,int next,int flow,int cap,int rev) {
		this->to    = to;
		this->next  = next;
		this->flow  = flow;
		this->cap   = cap;
		this->rev   = rev;
	}
};

struct DINIC {
	EDGE edge[EDGEMAX];
	int cnt,s,t;
	int dis[EDGEMAX],head[NODEMAX],cur[NODEMAX],vis[EDGEMAX];
	DINIC() {
		memset(head,-1,sizeof(head));
		cnt=-1;
	}
	void addEdge(int a,int b,int cap) {
		cnt++;
		edge[cnt].init(b,head[a],0,cap,cnt^1); head[a] = cnt;
		cnt++;
		edge[cnt].init(a,head[b],0,0,cnt^1); head[b] = cnt;
	}

	bool bfs() {
		for(int i=0; i<=cnt; i++) vis[i] = 0;
		int now,i;
		queue<int> list;
		list.push(s);
		dis[s] = 0;
		vis[s] = 1;
		while(!list.empty()) {
			now = list.front();
			list.pop();
			for(i=head[now]; i!=-1; i=edge[i].next) {
				EDGE& e = edge[i];
				if(!vis[e.to] && e.cap > e.flow) {
					vis[e.to] = 1;
					dis[e.to] = dis[now] + 1;
					list.push(e.to);
				}
			}
		}
		return vis[t];
	}
	int dfs(int now,int mff) {
		if(now == t || mff == 0) return mff;
		int f,flow = 0;
		for(int& i = cur[now]; i!=-1; i=edge[i].next) {
			EDGE& e = edge[i];
			if(dis[e.to] == (dis[now] + 1) && (f  = dfs(e.to,min(mff,e.cap-e.flow))) > 0) {
				e.flow += f;
				edge[e.rev].flow -= f;
				flow += f;
				mff -= f;
				if(mff==0) break;
			}
		}
		return flow;
	}
	int getMaxFlow(int s,int t) {
		int flow = 0;
		this->s = s;
		this->t = t;
		
		while(bfs()) {
			for(int i=0; i<=n; i++) cur[i] = head[i];
			flow += dfs(s,inf);
		}
		return flow;
	}
};

int main() {
	DINIC dinic;
	int to,next,w,s,t;
	cin >> n >> m >> s >> t;
	for(int i=0; i<m; i++) {
		cin >> to >> next >> w;
		dinic.addEdge(to,next,w);
	}
	cout << dinic.getMaxFlow(s,t);
}
