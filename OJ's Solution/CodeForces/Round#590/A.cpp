#include <cstdio>

typedef long long ll;

int main() {
	ll t,sum;
	ll tmp,n;
	scanf("%lld",&t);
	while(t--) {
		sum = 0;
		scanf("%lld",&n);
		for(int i=0; i<n; i++) {
			scanf("%lld",&tmp);
			sum+=tmp;
		}
		printf("%lld\n",sum/n + (sum%n!=0));
	}
}


