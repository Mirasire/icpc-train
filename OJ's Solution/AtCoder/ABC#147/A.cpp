#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
	ll tmp,ans = 0;
	for(int i=0; i<3; i++) {
		scanf("%lld",&tmp);
		ans+=tmp;
	}
	if(ans >= 22) printf("bust");
	else printf("win");
	return 0;
}
