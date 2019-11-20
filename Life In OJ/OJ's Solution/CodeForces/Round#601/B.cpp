#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
 
const int maxn = 1e3+100;
struct NODE {
	int num;
	int pos;
} a[maxn];
 
bool cmp(NODE& a,NODE &b) {
	return a.num < b.num;
}
 
int main() {
	int t,n,m;
	int ans = 0;
	scanf("%d",&t);
	while(t--) {
		ans = 0;
		scanf("%d%d",&n,&m);
		for(int i=0; i<n; i++) {
			scanf("%d",&a[i].num);
			a[i].pos = i+1;
			ans += a[i].num;
		}
		ans <<= 1;
		if(m<n || n==2) {
			printf("-1\n");
			continue;
		} else {
			sort(a,a+n,cmp);
			ans += (a[0].num+a[1].num)*(m-n);
			printf("%d\n",ans);
			int end = m-n;
			for(int i=1; i<=n; i++) {
				if(i!=n) 
					printf("%d %d\n",i,(i+1));
				else 
					printf("%d %d\n",i,1);
			}
			for(int i=0; i<end; i++) {
				printf("%d %d\n",a[0].pos,a[1].pos);
			}
		}
	}
	return 0;
}
