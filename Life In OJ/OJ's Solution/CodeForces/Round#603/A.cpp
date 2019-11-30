#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int main() {
	int n,t,ans;
	int a[3];
	cin >> n;
	while(n--) {
		cin >> a[0] >> a[1] >> a[2];
		sort(a,a+3);
		ans = a[0];
		if(a[2]-a[1] >= a[0]) ans += a[1];
		else {
			int remain = ans - a[2] + a[1];
			ans += a[1] - (remain+1)/2;
		}
		cout << ans << endl;
	}
	return 0;
}
