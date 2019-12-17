#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const	int maxn = 2e5+100;
struct SECTION {
	ll l,r;
	SECTION() {}
	SECTION(ll l,ll r):l(l),r(r) {}
	bool operator<(const SECTION& oth) const {
		if(l==oth.l) return r < oth.r;
		return l < oth.l;
	}
	bool operator==(const SECTION& oth) const { return l==oth.l&&r==oth.r; }
};
map<ll,int> idx;
vector<SECTION> sec[maxn];
ll N,X,D;

int main() {
	std::ios::sync_with_stdio(false);
	ll kl=0,kr=0,key,cnt = 0,ans = 0;
	cin >> N >> X >> D;
	if(D==0) {
		if(!X) cout << 1 << endl;
		else cout << N+1 << endl;
		return 0;
	} else if(D<0) {
		X*=-1;
		D*=-1;
	}
	ll l,r;
	for(int i=0; i<=N; i++) {
		key = i*X;
		ll bb = key%D;
		l = r = key/D;
		l+=kl; r+=kr;
		if(l>r) swap(l,r);
		if(idx[bb]==0ll) idx[bb] = ++cnt;
		sec[idx[bb]].push_back({--l,r});
		kl+=i,kr+=N-i-1;
	}
	for(int i=1; i<=cnt; i++) {
		SECTION tp;
		sort(sec[i].begin(),sec[i].end());
		tp = sec[i][0];
		for(SECTION now: sec[i]) {
			if(now.l <= tp.r) tp.r = max(tp.r,now.r);
			else {
				ans += tp.r-tp.l;
				tp = now;
			}

			if(now == sec[i].back()) {
				ans += tp.r-tp.l;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
