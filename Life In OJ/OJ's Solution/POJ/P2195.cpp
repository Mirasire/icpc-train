#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
using namespace std;

struct ND {
	int x,y;
	ND(){}
	ND(int x,int y):x(x),y(y) {}
};

string l[120];
vector<ND> man,house;

//tmplate_Use
//mcmf(s, t) return MaxFlow
//ret means MinCost
//addedge(u, v, w, c)

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
	int h,w;
	while(1) {
		cin >> h >> w;
		if(!(h||w)) break;
		//Init
		man.clear(); house.clear();
		memset(lnk,0,sizeof(lnk));
		for(int i=0; i<h; i++) {
			cin >> l[i];
			for(int j=0; j<w; j++) {
				if(l[i][j]=='m') man.push_back(ND(i,j));
				else if(l[i][j]=='H') house.push_back(ND(i,j));
			}
		}
		int msize = man.size(),hsize = house.size();
		int s = (msize+hsize)*2+8,t = (msize+hsize)*2+9;
		//s -> man
		for(int i=0; i<msize; i++) addedge(s,i,1,0);
		//t
		for(int i=0; i<hsize; i++) {
			addedge(msize+i,msize+hsize+i,1,0);
			addedge(msize+hsize+i,t,INF,0);
		}
		//link
		for(int i=0; i<msize; i++) {
			ND& mm = man[i];
			for(int j=0; j<hsize; j++) {
				ND& hh = house[j];
				int cost = abs(mm.x - hh.x) + abs(mm.y - hh.y);
				addedge(i,j+msize,1,cost);
			}
		}
		ret = 0;
		mcmf(s,t);
		cout << ret << endl;
	}
	return 0;
}
