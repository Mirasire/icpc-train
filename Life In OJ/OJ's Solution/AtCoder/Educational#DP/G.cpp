#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+100;
vector<int> head[maxn];
int in[maxn],dp[maxn];
bool vis[maxn];

int main() {
	std::ios::sync_with_stdio(false);
	int n,m,u,v;
	scanf("%d%d",&n,&m);
	for(int i=0; i<m; i++) {
		scanf("%d%d",&u,&v);
		head[u].push_back(v);
		in[v]++;
	}
	int ans = 0;
	queue<int> list;
	for(int i=1; i<=n; i++) {
		if(!in[i]) list.push(i);
	}
	int now;
	while(!list.empty()) {
		now = list.front();
		list.pop();
		for(int i=0; i<head[now].size(); i++) {
			int u = head[now][i];
			if(in[u]) {
				dp[u] = max(dp[u],dp[now]+1);
				in[u]--;
				if(!in[u]) list.push(u);
			}
		}
	}
	for(int i=1; i<=n; i++) ans = max(ans,dp[i]);
	printf("%d",ans);
	return 0;
}
