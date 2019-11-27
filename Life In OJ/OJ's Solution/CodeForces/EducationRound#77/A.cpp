#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int main() {
	long long int n;
	scanf("%lld",&n);
	while(n--) {
		long long int c,sum;
		scanf("%lld%lld",&c,&sum);
		long long int t = sum/c;
		long long int el = sum%c;
		long long int ans = 0;
		for(int i=0; i<c; i++) {
			if(i<el) ans += (t+1)*(t+1);
			else ans += t*t;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
