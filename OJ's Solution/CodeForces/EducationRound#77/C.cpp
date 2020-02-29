#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int main() {
	int t,r,b,k,gcd;
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d%d",&r,&b,&k);
		if(r>b) swap(r,b);
		gcd = __gcd(r,b);
		if((b-1-gcd)/r+1 >= k) puts("REBEL");
		else puts("OBEY");
	}
	return 0;
}
