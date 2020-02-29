//binary_search_1
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

typedef long long int ll;
const int maxn = 1e5+100;
ll n,c,diff[maxn],arr[maxn];

bool check(ll diffValue) {
	ll cnt = 0,sum = 0;
	for(int i=1; i<n; i++) {
		sum += diff[i];
		if(sum >= diffValue) cnt++,sum = 0;
		if(cnt == c) return 1;
	}
	return 0;
}

ll binary_search(ll N) {
	ll l = 0,r = N+1,mid;
	while(l+1<r) {
		mid = (l+r)>>1;
		if(check(mid)) l = mid;
		else r = mid;
	}
	return l;
}

int main() {
	scanf("%lld%lld",&n,&c);
	c--;
	for(int i=0,j; i<n; i++) {
		scanf("%lld",&arr[i]);
	}
	sort(arr,arr+n);
	for(int i=1; i<n; i++) diff[i] = arr[i] - arr[i-1];
	printf("%lld",binary_search((ll)(1e9)));
	return 0;
}
