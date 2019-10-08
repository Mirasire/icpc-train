#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;
const ll Maxn = 1e3+100,MOD = 1e9+7;
ll c[Maxn],r[Maxn];
ll nc[Maxn],nr[Maxn];

ll qfac(ll a) {
	ll sum = 1,bsc=2;
	while(a) {
		if(a&1) sum = (sum*bsc) % MOD;
		bsc = bsc*bsc%MOD;
		a>>=1;
	}
	return sum;
}

int main() {
	ll a,b;
	ll cnt = 0;
	scanf("%lld%lld",&a,&b);
	for(int i=1; i<=a; i++) {
		scanf("%lld",r+i);
		nr[i] = r[i];
		r[i]++;
	}
	for(int i=1; i<=b; i++) {
		scanf("%lld",c+i);
		nc[i] = c[i];
		c[i]++;
	}
	for(int i=1; i<=a; i++) {
	    for(int j=1; j<=b; j++) {
			if((j == r[i] && i < c[j]) || (i==c[j] && j<r[i])) {
				printf("0");
				return 0;
			}
			if(j > r[i] && i > c[j]) cnt++;
	    }
    }
	printf("%lld",qfac(cnt));
	return 0;
}
