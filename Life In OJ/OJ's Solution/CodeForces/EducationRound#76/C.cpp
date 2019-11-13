#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <limits.h>
using namespace std;

void slove() {
	int n,tmp;
	int ans = INT_MAX;
	map<int,int> per;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%d",&tmp);
		if(per[tmp]) ans = min(ans,i-per[tmp]+1);
		per[tmp] = i;
	}
	if(ans==INT_MAX) printf("-1\n");
	else printf("%d\n",ans);
}

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		slove();
	}
	return 0;
}
