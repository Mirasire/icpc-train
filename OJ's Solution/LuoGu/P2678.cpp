//AC
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
using namespace std;

typedef long long int ll;
const int maxn = 5e4+100;
int st = 1e9;
ll sub[maxn],l,n,m,per=0,tmp;

bool check(const ll& tar) {
	int now = sub[0],bt = m;
	for(int i=1; i<=n; i++) {
		if(bt && now<tar) now += sub[i],bt--;
		else if(now >= tar) now = sub[i];
		if(!bt && now < tar) return 0;
	}
	return now>=tar;
}

int find(ll st) {
	ll l = 1,r = st+1,mid;
while((l+1)<r) {
		mid = (l+r)>>1;
		if(check(mid)) l = mid;
		else r = mid;
	}
	return l;
}

int main() {
	scanf("%lld%lld%lld",&l,&n,&m);
	for(int i=0; i<n; i++) {
		scanf("%lld",&tmp);
		sub[i] = tmp - per;
		per = tmp;
	}
	sub[n] = l - per;
	ll out = find(l);
	printf("%lld\n",out);
	return 0;
}
