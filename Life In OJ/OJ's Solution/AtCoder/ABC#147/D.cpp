#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 3e5+100,MOD = 1e9+7;
ll arr[maxn],bits[maxn][2],tt[maxn];

int main() {
    ll n,ans;
    tt[0] = 1;
    for(int i=0; i<=60; i++) {
        tt[i] = tt[i]*2%MOD;
    }
    //slove()
    scanf("%lld",&n);
    for(int i=0; i<n; i++) scanf("%lld",&arr[i]);
    printf("%lld\n",ans);
    return 0;
}