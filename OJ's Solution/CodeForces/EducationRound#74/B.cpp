#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1e5+100;
int x[maxn],n,r;

int main() {
	int q,size;
	long long cnt = 0;
	scanf("%d",&q);
	while(q--) {
		cnt = 0;
		scanf("%d%d",&n,&r);
		for(int i=0; i<n; i++) scanf("%d",x+i);
		sort(x,x+n);
		size = unique(x,x+n) - x;
		for(int j=size-1; j>=0; ){
			while(x[j]-cnt*r <= 0) {
				j--;
				if(j==-1) break;
			}
			if(j!=-1) {
				cnt++;
				j--;
			}
		}
		printf("%lld\n",cnt);
	}
}
