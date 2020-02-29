#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll getVal(string str) {
	ll ans = 1;
	for(int i=0; i<str.size(); i++) {
		char&a = str[i];
		ans *= (int)a-(int)'A'+1;
	}
	return ans;
}

int main() {
	int a,b;
	std::ios::sync_with_stdio(false);
	string star,group;
	cin >> star >> group;
	a = b = 0;
	a = getVal(star);
	b = getVal(group);
	if(a%47 == b%47) cout << "GO\n";
	else cout << "STAY\n";
	return 0;
}
