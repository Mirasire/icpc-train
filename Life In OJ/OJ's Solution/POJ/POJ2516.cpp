#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
using namespace std;

#define prt(x) printf(#x " = %d\n",x);

int NN,MM,KK;


//tmplate_Use
//mcmf(s, t) return MaxFlow
//ret means MinCost
//addedge(u, v, captical, cost)

const int N = 5e3 + 5, M = 1e5 + 5;
const int INF = 0x3f3f3f3f;
int n, m, tot = 1, lnk[N], cur[N], ter[M], nxt[M], cap[M], cost[M], dis[N], ret;
bool vis[N];

void add(int u, int v, int w, int c) {
	ter[++tot] = v, nxt[tot] = lnk[u], lnk[u] = tot, cap[tot] = w, cost[tot] = c;
}
void addedge(int u, int v, int w, int c) { add(u, v, w, c), add(v, u, 0, -c); }
bool spfa(int s, int t) {
	memset(dis, 0x3f, sizeof(dis));
	memcpy(cur, lnk, sizeof(lnk));
	std::queue<int> q;
	q.push(s), dis[s] = 0, vis[s] = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop(), vis[u] = 0;
		for (int i = lnk[u]; i; i = nxt[i]) {
			int v = ter[i];
			if (cap[i] && dis[v] > dis[u] + cost[i]) {
				dis[v] = dis[u] + cost[i];
				if (!vis[v]) q.push(v), vis[v] = 1;
			}
		}
	}
	return dis[t] != INF;
}
int dfs(int u, int t, int flow) {
	if (u == t) return flow;
	vis[u] = 1;
	int ans = 0;
	for (int &i = cur[u]; i && ans < flow; i = nxt[i]) {
		int v = ter[i];
		if (!vis[v] && cap[i] && dis[v] == dis[u] + cost[i]) {
			int x = dfs(v, t, std::min(cap[i], flow - ans));
			if (x) ret += x * cost[i], cap[i] -= x, cap[i ^ 1] += x, ans += x;
		}
	}
	vis[u] = 0;
	return ans;
}

int mcmf(int s, int t) {
	int ans = 0;
	while (spfa(s, t)) {
		int x;
		while ((x = dfs(s, t, INF))) ans += x;
	}
	return ans;
}

int main() {
	while(~scanf("%d%d%d",&NN,&MM,&KK)) {
		int tmp;
		if(!(NN||MM||KK)) break;
		int ss = NN*KK*2+MM*KK*2+50,tt = ss+1;
		int b1 = NN*KK,b2 = NN*KK*2+MM*KK;
		//N
		for(int i=0; i<NN; i++) {
			for(int j=0; j<KK; j++) {
				scanf("%d",&tmp);
				addedge(b1+i*KK+j,b2+i*KK+j,tmp,0);
				addedge(b2+i*KK+j,tt,INF,0);
			}
		}
		//M
		b1 = 0,b2 = NN*KK + MM*KK;
		for(int i=0; i<MM; i++) {
			for(int j=0; j<KK; j++) {
				scanf("%d",&tmp);
				addedge(ss,i*KK+j,INF,0);
				addedge(i*KK+j,b2+i*KK+j,tmp,0);
			}
		}
		//link M---->N
		b1 = NN*KK+MM*KK,b2 = NN*KK;
		for(int k=0; k<KK; k++) {
			for(int i=0; i<NN; i++) {
				for(int j=0; j<MM; j++) {
					scanf("%d",&tmp);
					addedge(b1+j*KK+k,b2+i*KK+k,INF,tmp);
				}
			}
		}
		ret = 0;
		//====================Fordebug====================
		prt(NN);
		prt(MM);
		prt(KK);
		prt(ss);
		prt(tt);
		//====================Fordebug====================
		mcmf(ss,tt);
		printf("%d\n",ret);
	}
	return 0;
}
