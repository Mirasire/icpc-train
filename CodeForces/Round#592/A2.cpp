#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;


int main() {
	int n,a,b,c,d,k,sk;
	int sa,sb;
	cin >> n;
	while(n--) {
		sk = 0;
		cin >> a >> b >> c >> d >> k;
		sa = (a/c)+(int)(a%c!=0);
		sb = (b/d)+(int)(b%d!=0);
		sk = sa+sb;
		if(sk <= k) cout << sa << " " << sb << endl;
		else cout << -1 << endl;
	}
	return 0;
}
