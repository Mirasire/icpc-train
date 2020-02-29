#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

int main() {
	int n,x,a,b;
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> x >> a >> b;
		cout << min(n-1,abs(a-b)+x) << endl;
	}
	return 0;
}
