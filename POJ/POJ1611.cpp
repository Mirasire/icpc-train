#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 3e4 + 100;
int f[maxn], n, m;

int fi(int id) {
	if (id == f[id]) return id;
	else return f[id] = fi(f[id]);
}

void unite(int a, int b) {
	int r_a = fi(a);
	int r_b = fi(b);
	if(r_a != r_b) f[r_a] = r_b;
	return;
}

int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		if (n == 0 && m == 0) break;
		for (int i = 0; i < n; i++) f[i] = i;
		while (m--) {
			int k,x,y;
			scanf("%d%d", &k, &x);
			for (int i = 1; i < k; i++) {
				scanf("%d",&y);
				unite(x,y);
			}
		}
		int cnt = 0;
		int res = fi(0);
		for (int i = 0; i < n; i++) if (fi(i) == res) cnt++;
		printf("%d\n", cnt);
	}
	return 0;
}

