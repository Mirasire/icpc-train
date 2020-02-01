#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll a,b,c;
ll A,B,C;

bool isIn(ll val) { return val >= 100 && val <=999; }
bool isLegal() {
	bool vis[12] = {0};
	ll tmp = a*(int)1e6+b*(int)1e3+c;
	while(tmp) {
		vis[tmp%10]=1;
		tmp/=10;
	}
	for(int i=1; i<=9; i++) {
		if(!vis[i]) return 0;
	}
	return 1;
}

int main() {
	std::ios::sync_with_stdio(false);
	cin >> A >> B >> C;
	ll k = 100/A;
	bool flag = 1;
	while(1) {
		a = A*k; b = B*k; c = C*k;
		if(a>999 || b>999 || c>999) break;
		else if(isIn(a)&&isIn(b)&&isIn(c)&&isLegal()) {
			flag = 0;
			cout << a << " " << b << " " << c << endl;
		}
		k++;
	}
	if(flag) cout << "No!!!\n";
	return 0;
}
