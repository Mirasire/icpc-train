#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e4+100;
int n,k;
int f[maxn],rl[maxn];
int find(int u) {
	if(f[u]!=u) {
		int i=f[u];
		f[u]=find(f[u]);
		rl[u]=(rl[u]+rl[i])%3;
	}
	return f[u];
}

//a eat b
int merge(int a,int b,int rela) {
	if(a>n||b>n) return 1;
	int fa=find(a);
	int fb=find(b);
	if(fa!=fb) {
		f[fa]=fb;
		rl[fa]=(rl[b]+rela-rl[a]+3)%3;
		return 0;
	}
	return (rl[a]+rl[fa]-rl[b]+3)%3!=rela;
}

void init(int n) {
	for(int i=0; i<=n; i++) rl[i]=0,f[i]=i;
}

int main() {
	std::ios::sync_with_stdio(false);
	cin >> n >> k;
	init(n);
	int a,b,c,ans;
	ans = 0;
	while(k--) {
		cin >> c >> a >> b;
		ans+=merge(a,b,c-1);
	}
	cout << ans << endl;
	return 0;
}
