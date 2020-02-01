#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll bsc[21];

int main() {
	std::ios::sync_with_stdio(false);
	ll n,fac=1;
	cin >> n;
	if(n<=0) {
		n*=-1; fac*=-1;
	}
	ll ans = 0;
	while(n) {
		ans*=10;
		ans+=n%10;
		n/=10;
	}
	cout << ans*fac << endl;
	return 0;
}
