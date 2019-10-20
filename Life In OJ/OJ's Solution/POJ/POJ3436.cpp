#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

//Dinic Init
/* DebugList
 * cout << now << " --> " << e.to << "ff: " << e.cap - e.flow << " mff: " << mff << " t: " << t << endl;

	for(int j=0; j<=n*2+1; j++)
		for(int i=dinic.head[j]; i!=-1; i=dinic.edge[i].next) {
			cout << j << "-->" << dinic.edge[i].to << endl;
		}
 */

const int Pmaxn = 70;
const int MaxNode = Pmaxn*Pmaxn;
const int inf = 0x3f3f3f3f;
int p,n;
int out[Pmaxn][3];
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
	EDGE edge[MaxNode];
	int cnt,s,t;
	int dis[MaxNode],head[MaxNode],cur[MaxNode],vis[MaxNode];
	DINIC() {
		memset(head,-1,sizeof(head));
		cnt=-1;
	}
	void init() {
		memset(head,-1,sizeof(head));
		cnt = -1;
	}
	void addEdge(int a,int b,int cap) {
		edge[++cnt].init(b,head[a],0,cap,cnt^1); head[a] = cnt;
		edge[++cnt].init(a,head[b],0,0,cnt^1); head[b] = cnt;
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
				//cout << now << " --> " << e.to << " ff: " << e.cap - e.flow << endl;
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
			//f = dfs(e.to,min(mff,e.cap - e.flow));
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
			for(int i=0; i<=n*2+1; i++) cur[i] = head[i];
			flow += dfs(s,inf);
		}
		return flow;
	}
} dinic;

//for save
struct INPUT {
	int val,inp[13],out[13];
} inpt[60];

void slove(int s,int t);

int main() {
	int s,t;
	while(~scanf("%d%d",&p,&n)) {
		dinic.init();
		for(int i=1; i<=n; i++) {
			scanf("%d",&inpt[i].val);
			for(int j=0; j<p; j++) scanf("%d",&inpt[i].inp[j]);
			for(int j=0; j<p; j++) scanf("%d",&inpt[i].out[j]);
		}
		//perdu
		
		//link to the source
		s = 0;
		t = n*2+1;
		for(int i=1; i<=n; i++) {
			bool flag=1;
			for(int j=0; j<p&&flag; j++) {
				if(inpt[i].inp[j]==1) flag=0;
			}
			if(flag) dinic.addEdge(s,i,inf);
		}

		//拆点
		for(int i=1; i<=n; i++) dinic.addEdge(i,i+n,inpt[i].val);

		for(int u=1; u<=n; u++) {
			for(int v=1; v<=n; v++) {
				if(u==v) continue;
				bool flag = 1;
				for(int i=0; i<p&&flag; i++) {
					if(inpt[u].out[i] != inpt[v].inp[i] && inpt[v].inp[i] != 2) flag = 0;
				}
				if(flag) dinic.addEdge(u+n,v,inf);
			}
		}

		for(int i=1; i<=n; i++) {
			bool flag=1;
			for(int j=0; j<p&&flag; j++) {
				if(inpt[i].out[j]!=1) flag=0;
			}
			if(flag) dinic.addEdge(i+n,t,inf);
		}

		slove(s,t);
	}
	return 0;
}

void slove(int s,int t) {
	int maxFlow = dinic.getMaxFlow(s,t);
	int ctt = 0;
	int end = n*n;
	for(int i=n+1; i<=end; i++) {
		for(int j = dinic.head[i]; j!=-1; j=dinic.edge[j].next) {
			EDGE& e = dinic.edge[j];
			//cout << i << " --> " << e.to << " flow: " << e.flow << endl;
			if(e.cap && e.flow && e.to <= n) {
				out[ctt][0] = e.flow;
				out[ctt][1] = i-n;
				out[ctt++][2] = e.to;
			}
		}
	}
	printf("%d %d\n",maxFlow,ctt);
	for(int i=0; i<ctt; i++) {
		printf("%d %d %d\n",out[i][1],out[i][2],out[i][0]);
	}
}
