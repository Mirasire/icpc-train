#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 1e5+100;
int dp[maxn],jp[maxn];

int main() {
	int n;
	int dn,jn;
	long long int res = 0;
	scanf("%d",&n);
	int dt[4],jt[4];
	while(n--) {
		res = 0;
		jt[0] = dt[1] = 0;
		jt[1] = dt[0] = 0;
		scanf("%d",&dn);
		for(int i=0; i<dn; i++) {
			scanf("%d",dp+i);
			dt[(int)abs(dp[i]%2)]++;
		}
		scanf("%d",&jn);
		for(int i=0; i<jn; i++) {
			scanf("%d",jp+i);
			jt[(int)abs(jp[i]%2)]++;
		}
		res = (long long int)((long long int)dt[0]*jt[0]+(long long int)dt[1]*jt[1]);
		printf("%lld\n",res);
	}
	return 0;
}
