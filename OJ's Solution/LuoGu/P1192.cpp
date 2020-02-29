#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int maxn = 1e5+100,MOD = 100003;
ll arr[maxn];

int main() {
	ll n,k;
	scanf("%lld%lld",&n,&k);
	arr[0] = arr[1] = 1;
	for(int i=2; i<=k; i++)
		for(int j=0; j<i; j++)
			arr[i] = (arr[i]+arr[j])%MOD;
	for(int i=k+1; i<=n; i++)
		for(int j=1; j<=k; j++)
			arr[i] = (arr[i]+arr[i-j])%MOD;
	//for(int i=0; i<=n; i++) printf("%lld%c",arr[i]," \n"[i==n]);
	printf("%lld\n",arr[n]%MOD);
	return 0;
}
