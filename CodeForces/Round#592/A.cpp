#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;


int main() {
	int n; int a,b,c,d,k,sk;
	cin >> n;
	while(n--) {
		bool flag = 1;
		sk = 0;
		cin >> a >> b >> c >> d >> k;
		for(int i=0; i<=k&&flag; i++) 
			for(int j=0; j<=k&&flag; j++) {
				if(i*c>=a && j*d>=b && (i+j) <= k) {
					cout << i << " " << j << endl;
					flag=0;
				}
			}
		if(flag) cout << -1 << endl;
	}
	return 0;
}
