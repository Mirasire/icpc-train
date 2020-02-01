#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > p;
int ans = 0;

void dfs(vector<int> arr,int n,int t) {
	if(n==0&&t==10) {
		ans++;
		p.push_back(arr);
		return;
	}
	else if(n<=0 || t==10) return;
	arr.push_back(0);
	for(int i=1; i<=3; i++) {
		arr.back() = i;
		dfs(arr,n-i,t+1);
	}
	return;
}

int main() {
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> t;
	if(n>=10 && n<=30) {
		dfs(t,n,0);
		cout << ans << endl;
		for(int i=0; i<ans; i++) {
			for(int j=0; j<10; j++) {
				cout << p[i][j] << " ";
			}
			cout << endl;
		}
	} else {
		cout << 0 << endl;
	}
	return 0;
}
