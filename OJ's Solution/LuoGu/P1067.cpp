#include <bits/stdc++.h>
using namespace std;

const int maxn = 220;
int arr[maxn];

int main() {
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=n; i>=0; i--) cin >> arr[i];
	for(int i=n; i>=0; i--) {
		if(arr[i]) {
			if(i==n&&arr[i]<0)  cout << '-';
			else if(i<n) cout << (arr[i]>0? '+' : '-');
			if(abs(arr[i])>1&&i) cout << abs(arr[i]);
			else if(i==0) cout << abs(arr[i]);
			if(i) {
				if(i>1) cout << "x^" << i;
				else cout << "x";
			}
		}
	}
	return 0;
}
