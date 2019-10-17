#include <stdio.h>
#include <algorithm>
using namespace std;

#define _int64 long long int

int main() {
	int q;
	scanf("%d", &q);
	while (q--) {
		_int64 k, n, b, a;
		scanf("%lld%lld%lld%lld", &k, &n, &a, &b);
		if (k - b * n <= 0) {
			printf("-1\n");
			continue;
		}
		_int64 x = (k - b * n - 1) / (a - b);
		if (x > n) x = n;
		printf("%lld\n", x < 0 ? -1 : x);
	}
	return 0;
}
