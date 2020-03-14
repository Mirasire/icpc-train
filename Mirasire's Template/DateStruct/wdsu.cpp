const int maxn=1e5+100,MOD=123;
int dsu[maxn],val[maxn];
int find(int u) {
	if(dsu[u]!=u) {
		int t=dsu[u];
		dsu[u]=find(dsu[u]);
		val[u]=(val[t]+val[u])%MOD;
	}
	return dsu[u];
}
