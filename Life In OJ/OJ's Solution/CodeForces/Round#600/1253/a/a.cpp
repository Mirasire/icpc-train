#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int maxn = 1e5+100;
int a[maxn];

int main() {
	int t,n,tmp,jd,cnt;
	cin >> t;
	while(t--) {
		cnt = 0;
		cin >> n;
		for(int i=0; i<n; i++) cin >> a[i];
		for(int i=0; i<n; i++) {
			cin >> tmp;
			a[i] = tmp-a[i];
			if(a[i] < 0) cnt = 1;
		}
		int size = unique(a,a+n) - a;
		if(size > 3 || cnt) cout << "NO\n";
		else {
			for(int i=0; i<size; i++) {
				if(a[i]) cnt++;
			}
			if(cnt>1) cout << "NO\n";
			else cout << "YES\n";
		}
	}
	return 0;
}
