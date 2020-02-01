#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4+100;
int f[maxn];

int findFa(int n) {
	int us=n,ff;
	while(f[n] != n) n=f[n];
	while(f[us] != n) {
		ff = f[us];
		f[us] = n;
		us = ff;
	}
	return n;
}

int main() {
	std::ios::sync_with_stdio(false);
	int n,m;
	int o,a,b;
	cin >> n >> m;
	for(int i=0; i<=n; i++) f[i]=i;
	while(m--) {
		cin >> o >> a >> b;
		int fa = findFa(a);
		int fb = findFa(b);
		if(o==1) f[fa] = fb;
		else cout << (fa==fb? "Y\n" : "N\n");
	}
	return 0;
}
