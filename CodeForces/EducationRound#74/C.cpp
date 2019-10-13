#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int maxn = 2e5+100;
int p[maxn];

int main() {
	int t,i;
	int n,h,ans;
	scanf("%d",&t);
	while(t--) {
		ans = 0;
		scanf("%d%d",&h,&n);
		for(i=0; i<n; i++) scanf("%d",&p[i]);
		p[n] = 0;
		for(i=1; i<n; i++) {
			if(p[i]==p[i+1]+1) i++;
			else ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
