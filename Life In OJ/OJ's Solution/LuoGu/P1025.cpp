#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll ans,n,k;
void dfs(ll sum,ll t,ll p) {
	if(t==k) {
		if(sum==n) ans++;
		return;
	}
	int end = n-sum;
	for(ll i=p; i<=end; i++) dfs(sum+i,t+1,i);
}

int main() {
	cin >> n >> k;
	dfs(0,0,1);
	cout << ans << endl;
	return 0;
}
