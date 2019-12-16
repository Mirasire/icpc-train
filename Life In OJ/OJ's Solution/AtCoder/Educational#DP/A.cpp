#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int maxn = 1e5+100;
int h[maxn],dp[maxn];

int main() {
	int N;
	scanf("%d",&N);
	for(int i=1; i<=N; i++) scanf("%d",&h[i]);
	dp[1] = 0,dp[2] = abs(h[2]-h[1]);
	for(int i=3; i<=N; i++) dp[i] = min(dp[i-2]+abs(h[i]-h[i-2]),dp[i-1]+abs(h[i]-h[i-1]));
	printf("%d\n",dp[N]);
	return 0;
}
