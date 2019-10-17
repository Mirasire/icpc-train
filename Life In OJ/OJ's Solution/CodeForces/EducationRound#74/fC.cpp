#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;


int main() {
	int t,n,h,now,in,ans;
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d",&h,&n);
		now = h;
		ans = 1;
		while(n--) {
			scanf("%d",&in);
			if(in==now) ans--;
			else if(in < now) {
				ans++;
				now = in-1;
			}
			if(now==0) ans--;
		}
		printf("%d\n",ans);
	}
	return 0;
}
