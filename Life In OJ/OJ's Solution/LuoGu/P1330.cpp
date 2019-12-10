//坑点: 不保证全联通orz -^-明明说是一张图
//AC
#include <bits/stdc++.h>
using namespace std;

const int Hmaxn = 1e4+100,Emaxn = 1e5+100;
struct EDGE {
	int  to,nxt;
	void def(int a,int b) { to = a; nxt = b; }
} e[Emaxn<<1];
int head[Hmaxn],colo[Hmaxn],cnt;
int ans[2];
bool flag,vis[Hmaxn];

void addEdge(int u,int v) {
	e[++cnt].def(v,head[u]); head[u] = cnt;
	e[++cnt].def(u,head[v]); head[v] = cnt;
}

void dfs(int u,int ncolo) {
	if(!flag) return;
	colo[u] = ncolo;
	vis[u] = 1;
	ans[ncolo]++;
	for(int i=head[u]; i!=-1; i=e[i].nxt) {
		if(colo[e[i].to] == ncolo) {
			flag = 0;
			return;
		}
		else if(colo[e[i].to]==-1) dfs(e[i].to,1-ncolo);
	}
}


int main() {
	int n,m,res;
	int u,v,cnt;
	scanf("%d%d",&n,&m);

	//Init
	cnt = 0;
	for(int i=0; i<=n; i++) head[i] = colo[i] = -1;
	flag = 1;
	for(int i=0; i<m; i++) {
		scanf("%d%d",&u,&v);
		addEdge(u,v);
	}
	res = 0;
	for(int i=1; i<=n; i++) {
		if(!vis[i]) {
			ans[0] = ans[1] = 0;
			dfs(i,0);
			res+=min(ans[0],ans[1]);
			if(!flag) {
				printf("Impossible");
				return 0;
			}
		}
	}
	printf("%d",res);
	return 0;
}
