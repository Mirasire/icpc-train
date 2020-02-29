#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+100;
typedef long long int ll;

int main() {
	int n;
	int a,b,c,d,e,f;
	long long int ans = 0;
	cin >> a >> b >> c >> d >> e >> f;
	if(e>f) {
		ll m = min(a,d);
		d -= m;
		ans += e*m;
		ans += f*min(min(b,c),d);
	} else {
		ll m = min(min(b,c),d);
		d -= m;
		ans += f*m;
		ans += e*min(a,d);
	}
	cout << ans << endl;
	return 0;
}
