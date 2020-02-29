#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

typedef long long int ll;

int main() {
	int n;
	long long int a,b;
	scanf("%d",&n);
	while(n--) {
		scanf("%lld%lld",&a,&b);
		ll x = (2*a-b)/3;
		ll t = (2*b-a)/3;
		if(x>=0 && t>=0 && (2*a-b)%3==0 && (2*b-a)%3==0 ) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
