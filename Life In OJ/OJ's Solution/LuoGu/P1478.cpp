#include <bits/stdc++.h>
using namespace std;

#define mkp make_pair
#define all(v) v.begin(),v.end()
#define pir pair<int,int>

int n,s,a,b;
vector<pir> p;

int main() {
	std::ios::sync_with_stdio(false);
	int th,ts;
	cin >> n >> s >> a >> b;
	int h = a+b;
	for(int i=0; i<n; i++) {
		cin >> th >> ts;
		p.push_back(mkp(ts,th));
	}
	int ans = 0;
	sort(all(p));
	for(int i=0; i<n; i++) {
		pir& now = p[i];
		if(now.second <= h && now.first <= s) {
			s-=now.first;
			ans ++;
		} else if(now.first > s) break;
	}
	cout << ans << endl;
	return 0;
}
