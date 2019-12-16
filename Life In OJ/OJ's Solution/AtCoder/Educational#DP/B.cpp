#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+100;
int dp[maxn],arr[maxn];

int main() {
	std::ios::sync_with_stdio(false);
	int N,K;
	cin >> N >> K;
	for(int i=1; i<=N; i++) {
		cin >> arr[i];
		dp[i] = 0x3f3f3f3f;
	}
	dp[0] = dp[1] = 0;
	for(int k=2; k<=N; k++)
		for(int i=min(k-1,K); i>0; i--) dp[k] = min(dp[k],dp[k-i]+abs(arr[k]-arr[k-i]));
	cout << dp[N] << endl;
	return 0;
}
