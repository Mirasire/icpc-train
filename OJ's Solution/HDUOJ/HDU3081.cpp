//AC O(n^3)
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;


//Let boy 1+n-n<<1 gril-1-n
const int maxn = 230;
int n,m,f; //people m-<b,g> f-<g,g>
int fa[maxn],grp[maxn][maxn],match[maxn];
bool vis[maxn];

int findF(int u) {
	int tmp = u,ans;
	while(fa[tmp] != tmp) { tmp = fa[tmp]; }
	ans = tmp;
	while(fa[u] != ans) {
		tmp = fa[u];
		fa[u] = ans;
		u = tmp;
	}
	return ans;
}

void unite(int a,int b) {
	int ra = findF(a);
	int rb = findF(b);
	if(ra==rb) return;
	else fa[ra] = rb;
}

bool isMatch(int u) {
	int end = n<<1;
	for(int v=n+1; v<=end; v++) {
		if(grp[u][v] && !vis[v]) {
			vis[v] = 1;
			if(!match[v] || isMatch(match[v])) {
				match[v] = u;
				return 1;
			}
		}
	}
	return 0;
}

bool xyl() {
	//It's necessery to empty during every beginning
	memset(match,0,sizeof(match));
	int check = 0;
	for(int i=1; i<=n; i++) {
		memset(vis,0,sizeof(vis));
		check += isMatch(i);
	}
	return(check==n);
}

//make grile connet to boy
void buildGraph() {
	int end = n<<1;
	for(int i=n+1; i<=end; i++) {
		for(int j=1; j<=n; j++) {
			if(grp[j][i]) {
				for(int k=1; k<=n; k++) {
					if(findF(j) == findF(k)) {
						grp[i][k] = grp[k][i] = 1;
					}
				}
			}
		}
	}
}

int slove() {
	int ans = 0;
	while(xyl()) {
		ans++;
		for(int i=n+1; i<=(n*2); i++) grp[i][match[i]] = grp[match[i]][i] = 0;
	}
	return ans;
}

int main() {
	int t;
	int b,g;
	int g1,g2;
	scanf("%d",&t);
	while(t--) {
		//don't forget init
		memset(match,0,sizeof(match));
		memset(grp,0,sizeof(grp));
		scanf("%d%d%d",&n,&m,&f);
		for(int i=0; i<=(n<<1); i++) fa[i] = i;

		for(int i=0; i<m; i++) {
			scanf("%d%d",&g,&b);
			b+=n;
			grp[g][b] = grp[b][g] = 1;
		}
		for(int i=0; i<f; i++) {
			scanf("%d%d",&g1,&g2);
			unite(g1,g2);
		}
		//OK make sure the union set is OK
		buildGraph();
		printf("%d\n",slove());
	}
	return 0;
}
