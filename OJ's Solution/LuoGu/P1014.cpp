#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int n;

int main() {
	std::ios::sync_with_stdio(false);
	cin >> n;
	int sqn=sqrt(n),diff,x,y;
	while(sqn*(sqn+1)/2 < n) sqn++;
	sqn--;
	diff = n - sqn*(sqn+1)/2;
	if(sqn%2) {
		diff--;
		x = sqn+1; y=1;
		while(diff--) x--,y++;
	} else {
		diff--;
		x = 1; y=sqn+1;
		while(diff--) x++,y--;
	}
	cout << y << '/' << x << endl;
	return 0;
}
