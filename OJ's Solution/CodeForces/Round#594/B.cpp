#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int maxn = 1e5+100;
typedef long long int ll;
ll arr[maxn];

int main() {
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		scanf("%lld",arr+i);
	}
	int size = n/2;
	ll sum1 = 0,sum2 = 0;
	sort(arr,arr+n);
	for(int i=0; i<size; i++) {
		sum1 += arr[i];
	}
	for(int i=size; i<n; i++) {
		sum2 += arr[i];
	}
	ll sum = sum1*sum1 + sum2*sum2;
	printf("%lld",sum);
	return 0;
}
