#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

typedef long long int ll;
int main() {
	ll n,x,y;
	cin >> n;
	while(n--) {
		cin >> x >> y;
		if(x-y > 1) cout <<"YES\n";
		else cout << "NO\n";
	}
	return 0;
} 
