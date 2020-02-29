#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;


int main() {
	int t,x,y;
	cin >> t ;
	while(t--) {
		cin >> x >> y;
		if(x==1 && y!=1) cout << "NO\n";
		else if(x>=2 && x <=3 && y>3) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}
