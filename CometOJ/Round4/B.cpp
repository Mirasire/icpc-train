#include <cstring>
#include <cstdio>

typedef long long int64;
int64 get_sum(int64 d, const int64& k) {
	if (d < k) return (d + 1);
	int64 line = d / k;
	int64 zeros = line / (k + 1);
	zeros *= k;
	int64 restore = line % (k+1);
	if (restore) zeros += restore-1;
	int64 index = d % k;
	if (restore && restore-1 <= index) zeros++;
	return d - zeros + 1;
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int64 l, r, k;
		scanf("%lld%lld%lld", &l, &r, &k);
		if (k & 1) {
			printf("%lld\n", r - l + 1);
		}
		else {
			printf("%lld\n", get_sum(r, k) - get_sum(l - 1, k));
		}
	}
	return 0;
}
