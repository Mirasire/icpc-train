#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int maxn = 1e5+100;
int arr[maxn],pre[maxn],rev[maxn],psize,rsize,rsum;


int main() {
	int n=0,tmp;
	rsum = rsize = psize = 0;
	while(~scanf("%d",&tmp)) arr[n++] = tmp;
	pre[++psize] = arr[0];
	for(int i=1; i<n; i++) {
		if(arr[i] > pre[psize]) pre[++psize] = arr[i];
		else *(lower_bound(pre+1,pre+1+psize,arr[i])) = arr[i];
	}
	rev[++rsize] = arr[n-1];
	++rsum;
	for(int i=n-2; i>=0; i--) {
		if(arr[i] > rev[rsize]) {
			rev[++rsize] = arr[i];
			rsum++;
		}
		else {
			int ans = lower_bound(rev+1,rev+1+rsize,arr[i]) - rev;
			if(ans == arr[i]) rsum++;
			arr[ans] = arr[i];
		}
	}
	printf("%d\n",rsum);
	printf("%d\n",psize);
	return 0;
}
