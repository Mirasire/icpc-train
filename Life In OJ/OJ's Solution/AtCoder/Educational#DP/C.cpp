#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int maxn = 1e5+100;
int arr[maxn][4],dp[maxn][4];


int main() {
	std::ios::sync_with_stdio(false);
	int n,a,b,c,ans = 0;
	cin >> n;
	for(int i=1; i<=n; i++) cin >> arr[i][1] >> arr[i][2] >> arr[i][3];
	for(int i=1; i<=n; i++) {
		for(int k=1; k<=3; k++) {
			for(int j=1; j<=3; j++) {
				if(k==j) continue;
				dp[i][k] = max(dp[i-1][j]+arr[i][k],dp[i][k]);
			}
		}
	}
	cout << max(max(dp[n][1],dp[n][2]),dp[n][3]);
	return 0;
}
