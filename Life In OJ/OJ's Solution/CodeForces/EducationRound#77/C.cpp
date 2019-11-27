//wei AC
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <limits.h>
using namespace std;

typedef long long int ll;

int main() {
	int n;
	ll r,b,k,mxx;
	scanf("%d",&n);
	while(n--) {
		ll maxMod = INT_MIN;
		scanf("%lld%lld%lld",&r,&b,&k);
		map<int,bool> app;
		if(r>b) swap(r,b);
		mxx = (b-1)/r;
		if(r==b) {
			printf("OBEY\n");
			continue;
		}
		ll mod = b%r;
		ll end = sqrt(mod)+100;
		for(ll i=0; i<=end; i++) {
			app[mod] = 1;
			mxx = max(mxx,(b+mod-1)/r);
			mod = (b+mod)%r;
			if(app[mod] || mod < maxMod) break;
			maxMod = max(maxMod,mod);
		}
		if(mxx < k) 
			printf("OBEY\n");
		else 
			printf("REBEL\n");
	}
	return 0;
}
