//AC ^.^
#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e4+100;
int arr[maxn],diff[maxn],l,n,m;

bool check(int val) {
	int sum = diff[0],cnt = 0;
	for(int i=1; i<=n; i++) {
		if(sum >= val) {
			sum = diff[i];
		}
		else if(sum < val) {
			if(cnt < m) {
				sum += diff[i];
				cnt++;
			} else {
				return 0;
			}
		}
	}
	return 1;
}

int binary_search(int MM) { //imp
	int l=0,r=MM+1,mid;
	while(l+1<r) {
		mid = (l+r)>>1;
		if(check(mid)) l = mid;
		else r = mid;
	}
	return l;
}

int main() {
	scanf("%d%d%d",&l,&n,&m);
	arr[0] = 0;
	for(int i=1; i<=n; i++) scanf("%d",&arr[i]);
	sort(arr+1,arr+n+1);
	for(int i=0; i<n; i++) diff[i] = arr[i+1] - arr[i];
	diff[n] = l-arr[n];
	printf("%d",binary_search(l));
	return 0;
}
