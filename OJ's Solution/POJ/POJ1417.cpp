#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

#define debug(x) cout << #x << " = " << x << endl;

const int maxn =1e3+100;
int idx[maxn],dp[maxn][maxn],st[maxn][2],dsu[maxn],val[maxn];
bool vis[maxn],is[maxn][2];
int m,p1,p2,tot;
void init(int n) {
	tot=0;
	for(int i=0; i<=n; i++) {
		dsu[i]=i; 
		st[i][0]=st[i][1]=0;
		is[i][0]=is[i][1]=0;
		idx[i]=val[i]=vis[i]=0;
		for(int j=0; j<=n; j++) dp[i][j]=0;
	}
}
int find(int u) {
	if(dsu[u]!=u) { int tp=dsu[u]; dsu[u]=find(tp); val[u]=(val[u]+val[tp])%2; }
	return dsu[u];
}
void merge(int x,int y,int v) {
	int fa=find(x),fb=find(y);
	if(fa==fb) return;
	dsu[fa]=fb;
	val[fa]=((v+val[y]-val[x])%2+2)%2;
}

int main() {
	int x,y,fa,n;
	int k,rela;
	string op;
	std::ios::sync_with_stdio(false);
	while(cin >> m >> p1 >> p2) {
		if(m==p1&&p1==p2&&!m) break;
		n=p1+p2;
		init(n);
		for(int i=0; i<m; i++) {
			cin >> x >> y >> op;
			if(op=="yes") merge(x,y,0);
			else merge(x,y,1);
		}
		for(int i=1; i<=n; i++) {
			fa=find(i);
			if(!idx[fa]) idx[fa]=++tot;
			st[idx[fa]][(val[fa]+val[i])%2]++;
		}
		dp[0][0]=1;
		for(int i=1; i<=tot; i++) {
			for(int j=min(st[i][0],st[i][1]); j<=p1; j++) {
				if(dp[i-1][j-st[i][0]]) dp[i][j]+=dp[i-1][j-st[i][0]];
				if(dp[i-1][j-st[i][1]]) dp[i][j]+=dp[i-1][j-st[i][1]];
			}
		}
		if(dp[tot][p1]!=1) { cout << "no\n"; }
		else {
			k=p1;
			for(int i=tot; i>=1; i--) {
				if(dp[i-1][k-st[i][0]]==1) is[i][0]=1,k-=st[i][0];
				else is[i][1]=1,k-=st[i][1];
			}
			for(int i=1; i<=n; i++) {
				fa=find(i);
				rela=(val[fa]+val[i])%2;
				vis[i]=is[idx[fa]][rela];
			}
			for(int i=1; i<=n; i++) {
				if(vis[i]) cout << i << endl;
			}
			cout << "end\n";
		}
	}
	return 0;
}
