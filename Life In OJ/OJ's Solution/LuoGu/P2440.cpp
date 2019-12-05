//Binary_search the ans
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int maxn = 1e5+100,MM = 1e9;
int arr[maxn],n,k;

bool check(int val) {
	int ans = 0;
	for(int i=0; i<n; i++) ans+=arr[i]/val;
	return ans >= k;
}

int binary_search() {
	int l = 0, r = MM,mid;
	while(l+1<r) {
		mid = (l+r)>>1;
		if(check(mid)) l = mid;
		else r = mid;
	}
	return l;
}

int main() {
	scanf("%d%d",&n,&k);
	for(int i=0; i<n; i++) scanf("%d",&arr[i]);
	printf("%d\n",binary_search());
	return 0;
}
