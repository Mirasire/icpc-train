#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 3e5+100,MOD = 1e9+7;
ll arr[maxn],bits[maxn][2],tt[maxn];

int main() {
    ll n,ans = 0;
    tt[0] = 1;
    for(int i=1; i<=60; i++) {
        tt[i] = tt[i-1]*2%MOD;
    }
    //slove()
    scanf("%lld",&n);
    for(int i=0; i<n; i++) scanf("%lld",&arr[i]);
	for(int k=0; k<=60; k++) {
		for(int i=0; i<n; i++) {
			bits[k][arr[i]%2]++;
			arr[i]/=2;
		}
		ans = (ans+bits[k][0]*bits[k][1]%MOD*tt[k]%MOD)%MOD;
	}
	ans %= MOD;
    printf("%lld\n",ans);
    return 0;
}
