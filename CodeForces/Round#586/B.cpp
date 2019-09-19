#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;
const int M = 1e3+100;
ll el[M][M];

ll getSqrt(ll a,ll bsc) {
	ll end = bsc + 1000;
	for(ll i=max(bsc-1000,1ll); i<end; i++) 
		if(i*i == a) return i;
}

int main() {
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			scanf("%lld",&el[i][j]);
		}
	}
	ll a = (el[2][1]*el[1][3])/el[3][2];
	ll mid = sqrt(a);
	if(mid*mid != a) mid = getSqrt(a,mid);
	printf("%lld",mid);
	for(int i=2; i<=n; i++) {
		printf(" %lld",el[1][i]/mid);
	}
	return 0;
}
