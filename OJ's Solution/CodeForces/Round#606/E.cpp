#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;

typedef long long int ll;
const int Nmaxn = 2e5+100,Mmaxn = 5e5+100;
struct Edge {
	int to,nxt;
	void def(int _to,int _nxt) { to = _to; nxt = _nxt; }
} e[Mmaxn<<1];
int head[Nmaxn],cnt;
bool vis[Nmaxn];
void init(int n) {
	for(int i=0; i<=n; i++) { head[i] = -1; vis[i] = 0; }
	cnt = 0;
}
void addEdge(int a,int b) {
	e[++cnt].def(b,head[a]); head[a]=cnt;
}
void addNoDirEdge(int a,int b) {
	addEdge(a,b); addEdge(b,a);
}

int dfsCnt;
void dfs(int u,int &tar) {
	if(vis[u] || u==tar) return;
	vis[u]=1;
	dfsCnt++;
	for(int i=head[u]; i!=-1; i=e[i].nxt) {
		dfs(e[i].to,tar);
	}
	return;
}

int main() {
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	int n,m,a,b;
	int u,v;
	long long int ans;
	while(t--) {
		cin >> n >> m >> a >> b;
		init(n);
		for(int i=0; i<m; i++) {
			cin >> u >> v;
			addNoDirEdge(u,v);
		}
		dfsCnt = 0;
		dfs(a,b);
		ans = n-1-dfsCnt;
		dfsCnt = 0;
		for(int i=0; i<=n; i++) vis[i] = 0;
		dfs(b,a);
		ans *= n-1-dfsCnt;
		cout << ans << endl;
	}
	return 0;
}
