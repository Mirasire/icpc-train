#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll mod;
ll qfac(ll a,ll p) {
	ll ans = 1;
	a%=mod;
	while(p) {
		if(p&1) ans=ans*a%mod;
		a=a*a%mod;
		p>>=1;
	}
	return ans%mod;
}

int main() {
	std::ios::sync_with_stdio(false);
	ll a,p;
	cin >> a >> p >> mod;
	cout << a << "^" << p << " mod " << mod << "=";
	cout <<qfac(a,p);
	return 0;
}
