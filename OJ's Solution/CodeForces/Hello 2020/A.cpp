#include <bits/stdc++.h>
using namespace std;

const int maxn = 24;
string s[maxn],t[maxn];

int main() {
	std::ios::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	for(int i=0; i<n; i++) cin >> s[i];
	for(int i=0; i<m; i++) cin >> t[i];
	int T,ot;
	cin >> T;
	while(T--) {
		cin >> ot;
		ot--;
		cout << s[ot%n] << t[ot%m] << endl;
	}
	return 0;
}
