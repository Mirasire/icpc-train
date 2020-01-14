#include <bits/stdc++.h>
using namespace std;

const int maxn =  1e5+100;
using pi = pair<int,int>;

vector<pi> pr;
typedef long long int ll;

int main() {
	std::ios::sync_with_stdio(false);
	ll n,m;
	cin >> n;
	ll ans = n*n;
	for(int i=0; i<n; i++) {
		cin >> m; vector<ll> arr(m);
		for(int i=0; i<m; i++) cin >> arr[i];
		reverse(arr.begin(),arr.end());
		if(is_sorted(arr.begin(),arr.end())) pr.push_back(make_pair(arr[0],arr.back()));
	}
	sort(pr.begin(),pr.end());
	int _size = pr.size();
	for(int i=0; i<_size; i++)
		ans -= pr.end() - lower_bound(pr.begin(),pr.end(),pi(pr[i].second,-1));
	cout << ans << endl;
	return 0;
}
