#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const long long int maxn = 1e3+100;
struct NODE {
	long long int num;
	long long int pos;
} a[maxn];

bool cmp(NODE& a,NODE &b) {
	return a.num < b.num;
}

int main() {
	long long int t,n,m;
	long long int ans = 0;
	scanf("%lld",&t);
	while(t--) {
		ans = 0;
		scanf("%lld%lld",&n,&m);
		for(long long int i=0; i<n; i++) {
			scanf("%lld",&a[i].num);
			a[i].pos = i+1;
		}

		if(n==2) {
			ans = a[0].num+a[1].num;
			printf("%lld\n",ans*m);
			for(long long int i=0; i<m; i++) printf("1 2\n");
		}
		else if(m<(n-1)) {
			printf("-1\n");
			continue;
		} else {
			sort(a,a+n,cmp);
			for(int i=1; i<n; i++) {
				ans += a[0].num + a[i].num;
			}
			long long int end = m-n+1;
			ans += (a[0].num + a[1].num)*end;
			printf("%lld\n",ans);
			for(long long int i=1; i<n; i++) {
					printf("%lld %lld\n",a[0].pos,a[i].pos);
			}
			for(long long int i=0; i<end; i++) {
				printf("%lld %lld\n",a[0].pos,a[1].pos);
			}
		}
	}
	return 0;
}
