//Memory Limited 125.00MB
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned short int usl;
const int Vm = 5e3+5,Em = 1e5+4,INF = 0x3f3f3f;

struct EDGE {
	int to,next,flow,cap,cost;
	inline void init(int to,int next,int cap,int cost) {
		this->flow = 0;
		this->to = to;
		this->next = next;
		this->cap = cap;
		this->cost = cost;
	}
};

struct MCFC {
	int head[Vm],cur[Vm],dist[Vm];
	int s,t,cnt,maxFlow;
	int minCost;
	bool vis[Vm];
	EDGE edge[Em];
	MCFC() {
		memset(head,-1,sizeof(head));
		cnt = -1;
	}

	void AddEdge(int a,int b,int cap,int cost) {
		edge[++cnt].init(b,head[a],cap,cost); head[a] = cnt;
		edge[++cnt].init(a,head[b],0,-cost); head[b] = cnt;
	}

	bool spfa() {
		//init
		int now,i;
		fill(dist,dist+Vm,INF);
		memset(vis,0,sizeof(vis));
		memcpy(cur,head,sizeof(head)); //maybe for dfs?

		queue<int> list;
		list.push(s);
		vis[s] = 1;
		dist[s] = 0;
		while(!list.empty()) {
			now = list.front();
			list.pop();
			vis[now] = 0;
			//cout << "dist(now) " << dist[now] << endl;
			for(i = head[now]; i!=-1; i=edge[i].next) {
				//cout << "i " << i << endl;
				EDGE& e = edge[i];
				if(e.cap > e.flow && dist[e.to] > dist[now] + e.cost) {
					dist[e.to] = dist[now] + e.cost;
					if(!vis[e.to]) vis[e.to]=1,list.push(e.to);
				}
			}
		}
		return dist[t]!=INF;
	}

	int dfs(int u,int f) {
		if(u == t || f == 0) return f;
		//vis[u] = 1;
		int ff = 0,rf = 0;
		for(int& i=cur[u]; i!=-1; i=edge[i].next) {
			EDGE& e = edge[i];
			if(/*!vis[e.to] &&*/ (dist[e.to] == dist[u] + e.cost) && (ff = dfs(e.to,min(f,e.cap-e.flow))) > 0) {
				minCost += ff*e.cost; //计算费用
				//普通最大流操作
				e.flow += ff;	
				edge[i^1].flow -= ff;
				rf += ff;
				f -= ff;
				if(!f) break;
			}
		}
		//vis[u] = 0;
		return rf;
	}

	void mcfc(int s,int t) {
		minCost = maxFlow = 0;
		this->s = s; this->t = t;
		while(spfa()) maxFlow += dfs(s,INF);
		return;
	}
};

int main() {
	cout << sizeof(MCFC) << endl;
	MCFC dinic;
	int n,m,s,t;
	int a,b,c,co;
	scanf("%d%d%d%d",&n,&m,&s,&t);
	while(m--) {
		scanf("%d%d%d%d",&a,&b,&c,&co);
		dinic.AddEdge(a,b,c,co);
	}
	dinic.mcfc(s,t);
	printf("%d %d\n",dinic.maxFlow,dinic.minCost);
	return 0;
}
