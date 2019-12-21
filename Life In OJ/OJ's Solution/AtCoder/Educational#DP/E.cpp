#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5+120;
ll dp[maxn],v[120],w[120];

int main() {
	std::ios::sync_with_stdio(false);
    ll N,W,ans = 0;
    cin >> N >> W; 
	for(int i=1; i<maxn; i++) dp[i] = W+1;
	for(int i=1; i<=N; i++) cin >> w[i] >> v[i];
	for(ll i=1; i<=N; i++) {
		//1e3*100
		for(ll j=1e5+100; j>=v[i]; j--) {
			dp[j] = min(dp[j],dp[j-v[i]]+w[i]);
			if(dp[j] <= W) ans = max(ans,j);
		}
	}
	cout << ans << endl;
    return 0;
}
