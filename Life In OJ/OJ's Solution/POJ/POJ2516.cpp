#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#define debug(x) printf(#x " = %d\n",x)
using namespace std;


//tmplate_Use
//mcmf(s, t) return MaxFlow
//ret means MinCost
//addedge(u, v, w, c)

const int N = 5e3 + 5, M = 1e5 + 5;
const int INF = 0x3f3f3f3f;
int tot = 1, lnk[N], cur[N], ter[M], nxt[M], cap[M], cost[M], dis[N], ret;
bool vis[N];

void init() {
	memset(lnk,0,sizeof(lnk));
	tot = 1;
	ret = 0;
}
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

//for tmp_save
int arrSp[70][70],arrSuf[70][70],arrKds[70][70][70];

int main() {
	int sp,suf,kds;
	int tmp;
	while( ~scanf("%d%d%d",&sp,&suf,&kds)) {
		int res = 0,mf = 0,sum = 0;
		if(!(sp||suf||kds)) break;
		for(int i=0; i<sp; i++)
			for(int j=0; j<kds; j++) {
				scanf("%d",&arrSp[i][j]);
				sum += arrSp[i][j];
			}
		for(int i=0; i<suf; i++)
			for(int j=0; j<kds; j++)
				scanf("%d",&arrSuf[i][j]);
		for(int k=0; k<kds; k++)
			for(int i=0; i<sp; i++)
				for(int j=0; j<suf; j++)
					scanf("%d",&arrKds[k][i][j]);
		for(int k=0; k<kds; k++) {
			int s = N-10,t = s+1;
			init();
			//Link shopers to t
			for(int i=0; i<sp; i++) {
				addedge(i,i+sp,arrSp[i][k],0);
				addedge(i+sp,t,INF,0);
			}
			//Link s to suf
			for(int i=0; i<suf; i++) {
				if(arrSuf[i][k]) {
					addedge(s,2*sp+i,arrSuf[i][k],0);
				}
			}
			//link all to all
			for(int i=0; i<sp; i++) {
				for(int j=0; j<suf; j++) {
					if(arrKds[k][i][j]) {
						addedge(2*sp+j,i,INF,arrKds[k][i][j]);
					}
				}
			}
			mf+=mcmf(s,t);
			res += ret;
		}
		printf("%d\n",mf == sum? res : -1);
	}
	return 0;
}
