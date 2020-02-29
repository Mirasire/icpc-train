#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3+100;
struct RELA{
	int a,b,w;
} rela[100100];
bool cmp(RELA& a,RELA& b) {
	return a.w < b.w;
};

int f[maxn];
void init(int n) {
	for(int i=0; i<=n; i++) f[i]=i;
}

int find(int u) {
	if(f[u] != u) f[u] = find(f[u]);
	return f[u];
}

int main() {
	std::ios::sync_with_stdio(false);
	int n,m;
	int fa,fb;
	cin >> n >> m;
	init(n);
	for(int i=0; i<m; i++) cin >> rela[i].a >> rela[i].b >> rela[i].w;
	sort(rela,rela+m,cmp);
	int tis=n-1;
	for(int i=0; i<m; i++) {
		fa = find(rela[i].a);
		fb = find(rela[i].b);
		if(fa!=fb) {
			f[fa]=fb;
			tis--;
		}
		if(!tis) {
			cout << rela[i].w << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}
