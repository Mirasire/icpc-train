#include <cstdio>
#include <algorithm>
#include <limits.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		int n, k, t;
		int MIN = 1e9, MAX = -1;
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; i++) {
			scanf("%d", &t);
			MIN = min(t, MIN);
			MAX = max(t, MAX);
		}
		if (MIN + k < MAX - k) printf("-1\n");
		else {
			printf("%d\n", MIN + k);
		}
	}
	return 0;
}
