#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

const int maxn = 1e6+100;
int idx = 0;
int arr[maxn];

int main() {
	int n,size,t;
	scanf("%d",&n);
	while(n--) {
		idx = 0;
		scanf("%d",&t);
		arr[idx++] = 0;
		for(int i=1; i<=sqrt(t); i++) {
			arr[idx++] = t/i;
			arr[idx++] = t/(t/i);
		}
		sort(arr,arr+idx);
		idx = unique(arr,arr+idx) - arr;
		printf("%d\n",idx);
		for(int i=0; i<idx; i++) printf("%d ",arr[i]);
		putchar('\n');
	}
	return 0;
}
