#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3+100;

int main() {
	std::ios::sync_with_stdio(false);
	queue<int> list;
	set<int> st;
	int n,m,tp;
	int ans = 0;
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		cin >> tp;
		if(!st.count(tp)) {
			ans++;
			if(st.size() == n) {
				st.erase(list.front());
				list.pop();
			}
			list.push(tp);
			st.insert(tp);
		}
	}
	cout << ans << endl;
	return 0;
}
