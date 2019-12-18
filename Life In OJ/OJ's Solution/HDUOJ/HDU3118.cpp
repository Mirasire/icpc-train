//2019-SHU-K
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int maxn = 20;
int maz[maxn][maxn];
int sta[40];

int main() {
	std::ios::sync_with_stdio(false);
	ll t;
	cin >> t;
	while(t--) {
		//init
		memset(maz,0,sizeof(maz));
		ll n,m,u,v,ans = INT_MAX;
		cin >> n >> m;
		ll end = 1<<n;
		for(int i=0; i<m; i++) {
			cin >> u >> v;
			maz[u][v]++;
			maz[v][u]++;
		}
		for(ll k=0; k<end; k++) {
			//getset
			ll tp = k;
			ll tans = m;
			memset(sta,0,sizeof(sta));
			for(int i=0; i<n; i++) {
				if(tp&1) sta[i] = 1;
				tp>>=1;
			}
			for(int i=0; i<n; i++) {
				if(!sta[i]) {
					for(int j=0; j<n; j++) {
						if(sta[i]^sta[j]) tans-=maz[i][j];
					}
				}
			}
			ans = min(ans,tans);
		}
		cout << ans << endl;
	}
	return 0;
}
