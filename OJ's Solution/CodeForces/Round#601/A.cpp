#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;


int main() {
	int n;
	int a,b;
	int ans;
	scanf("%d",&n);
	while(n--) {
		ans = 0;
		scanf("%d%d",&a,&b);
		a = abs(a-b);
		ans += a/5;
		a%=5;
		ans += a/2;
		a%=2;
		ans += a/1;
		printf("%d\n",ans);
	}
	return 0;
}
