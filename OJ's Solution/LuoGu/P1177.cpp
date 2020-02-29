#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+100;
int arr[maxn],n;

int main() {
	std::ios::sync_with_stdio(false);
	cin >> n;
	for(int i=0; i<n; i++) cin >> arr[i];
	sort(arr,arr+n);
	for(int i=0; i<n; i++) cout << arr[i] << (i==n-1? '\n' : ' ');
	return 0;
}
