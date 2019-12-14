#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,num,ans = 0;
	cin >> n;
	while(n--) {
		int bsc = 0;
		ans = 0;
		cin >> num;
		for(int i=0; i<11 && bsc <= num; i++) {
			bsc = bsc*10 + 1;
			for(int j=1; j<=9; j++) {
				int key = bsc * j;
				if(key <= num) ans++;
				else {
					bsc = key;
					break;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
