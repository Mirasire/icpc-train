#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3+100;
typedef long long int ll;
ll ans[maxn];

ll getAns(int end) {
	ll res = 0;
	for(int i=1; i<=end; i++) res += ans[i];
	return res;
}

int main() {
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	ans[1] = 1; ans[2]=2;
	for(int i=1; i<=n; i++) {
		ans[i] = getAns(i/2)+1;
	}
	cout << ans[n] << endl;
	return 0;
}
