#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

const int maxn = 500,INF = 0x3f3f3f;
int n,m,k,t,cnt;
int head[maxn],dis[maxn],cur[maxn],vis[maxn];
int t[250][250],f[250][250];
struct REQUEST {
	int a,b,s,t,c;
	void init(int a,int b,int s,int t,int c) {
		this->a = a;
		this->b = b;
		this->s = s;
		this->t = t;
		this->c = c;
	}
} rq[250];
struct EDGE {
	int to,nx,cap,cost,res;
	void init(int to,int nx,int res,int cost) {
		this->to = to;
		this->nx = nx;
		this->res = res;
		this->cost = cost;
	}
} e[3300];

void addEdge(int from,int to,int cap,int cost) {
	e[++cnt].init(to,head[from],cap,cost); head[from] = cnt;
	e[++cnt].init(from,head[to],0,-cost); head[to] = cnt;
}

bool spfa() {
	fill(dis,dis+t+2,-INF);
	memset(vis,0,sizeof(vis));
	queue<int> list;
	list.push(s);
	vis[s] = 1;
	dis[s] = 0;
}

int main() {
	memset(head,-1,sizeof(head));
	scanf("%d%d%d%d",&n,m,k,t);
	int ss = m*2 + 5, tt =  m*2+10;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d",&t[i][j]);
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d",&f[i][j]);
	for(int i=0; i<m; i++)
		scanf("%d%d%d%d",&rq[i].a,&rq[i].b,&rq[i].s,&rq[i].t,&rq[i].c);
	for(int i=0; i<m; i++) {
		addEdge(i,i+m,1,rq[i].c);
		REQUEST& now = rq[i];
		//link to the target
		if(t[now.b][0]+now.t <= T) addEdge(i+m,tt,INF,-f[now.b][0]);
		else continue;

		//link to the source
		if(t[0][now.a] <= now.s) addEdge(m,i,INF,-f[0][now.a]);

		for(int j=0; j<m; j++) {
			if(i==j) continue;
			REQUEST& tg = rq[j];
			if()
		}
	}
	return 0;
}
