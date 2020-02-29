const int Vmaxn = 1e4+1000,Emaxn = 5e5+100,inf = 2147483647; //Vmaxn最大点的个数，Emaxn边的最大个数，inf看情况更改

struct EDGE{
	int to,next,w;
};

struct SPFA {
	int head[Vmaxn],d[Vmaxn],cnt,n;
	bool vis[Vmaxn];
	EDGE edge[Emaxn];

	SPFA() {
		cnt = 0;
		memset(head,-1,sizeof(head));
		memset(vis,0,sizeof(vis));
	}

	void init(int n) {
		cnt = 0;
		n = n;
		memset(head,-1,sizeof(int)*(n+1));
		memset(vis,0,sizeof(bool)*(n+1));
	}

	void AddEdge(int a,int b,int w) {
		edge[++cnt].to = b;
		edge[cnt].next = head[a];
		edge[cnt].w = w;
		head[a] = cnt;
	}

	void runSpfa(int s,int n) {
		int now;
		for(int i=0; i<=n; i++) d[i] = inf; //Re_Reason: n is error to m
		queue<int> list;
		list.push(s);
		vis[s] = 1;
		d[s] = 0;
		while(!list.empty()) {
			now = list.front();
			list.pop();
			vis[now] = 0;
			for(int i=head[now]; i!=-1; i=edge[i].next) {
				EDGE &e = edge[i];
				if(d[e.to] > d[now] + e.w) {
					d[e.to]  = d[now] + e.w;
					if(!vis[e.to]) {
						vis[e.to] = 1;
						list.push(e.to);
					}
				}
			}
		}
	}
};
