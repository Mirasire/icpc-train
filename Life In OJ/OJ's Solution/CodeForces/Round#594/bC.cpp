//DP
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int MAXN = 1e5+100,MOD = 1e9+7;
long long int dp[MAXN];

int main() {
	int n,m;
	cin >> n >> m;
	dp[1] = 2,dp[2] = 4;
	for(int i=3; i<=max(n,m); i++) {
		dp[i] = dp[i-1] + dp[i-2];
		dp[i] %= MOD;
	}
	cout << (dp[n] + dp[m] - 2)%MOD << endl;
	return 0;
}
