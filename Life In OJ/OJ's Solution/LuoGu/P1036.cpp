#include <bits/stdc++.h>
using namespace std;

int n,k;
const int maxn = 1e8+100;
bool vis[24];
int arr[24];
int ans;

bool isPrime(int nums) {
	int ed = sqrt(nums);
	for(int i=2; i<=ed; i++) if(!(nums%i)) return 0;
	return 1;
}

void dfs(int num,int ts,int sst) {
	if(ts == k) {
		if(isPrime(num)) ans++;
		return;
	}
	for(int i=sst; i<n; i++) {
		dfs(num+arr[i],ts+1,i+1);
	}
	return;
}

int main() {
	std::ios::sync_with_stdio(false);
	cin >> n >> k;
	for(int i=0; i<n; i++) cin >> arr[i];
	dfs(0,0,0);
	cout << ans << endl;
	return 0;
}
