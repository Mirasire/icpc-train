#include <bits/stdc++.h>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
    double a,b,l,r,now=0,add=7.0;
	cin >> a >> b;
	l = a-b; r=a+b;
	bool flag = 1;
	while(!(now>=l&&now<=r)) {
		if(flag) flag=0;
		else add*=0.98;
		now+=add;
	}
	now+=add==7.0? add:add*0.98;
	if(now>=l&&now<=r) cout << 'y';
	else cout << 'n';
	return 0;
}
