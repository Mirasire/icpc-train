#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;
int main() {
	ll n, r, l;
	cin >> n >> l >> r;
	ll minn = (1 << l) -1  + (n - l);
	ll maxx = max((1 << l) - 1 +(n - l) * (1 << l-1), (1<<r) -1 + (n - r) * (1 << r - 1));
	cout << minn << " " << maxx;
	return 0;
}
