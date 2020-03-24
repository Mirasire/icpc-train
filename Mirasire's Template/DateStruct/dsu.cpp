const int maxn = 1e5+100;
int dsu[maxn];
int find(int u) {
	int a=u,tp;
	while(dsu[u]!=u) u=dsu[u];
	while(dsu[a]!=u) {
		tp=dsu[a];
		dsu[a]=u;
		a=tp;
	}
	return u;
}
void merge(int a,int b) {
	int fa=find(a),fb=find(b);
	if(fa!=fb) dsu[fa]=fb;
}
