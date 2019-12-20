#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int maxn=1e5+100;
ll dp[maxn],v[maxn],w[maxn];

int main() {
	std::ios::sync_with_stdio(false);
	ll n,m;
	cin >> n >> m;
	for(int i=1; i<=n; i++) cin >> w[i] >> v[i];
	for(int i=1; i<=n; i++)
		for(int j=m; j>=w[i]; j--) dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
	cout << dp[m] << endl;
	return 0;
}
