//记忆化搜索
#include <bits/stdc++.h>
using namespace std;

#define mkp make_pair
#define pir pair<int,int>
typedef long long int ll;

map<pair<int,pir>,int> val;

ll w(ll a,ll b, ll c) {
	int& v = val[mkp(a,mkp(b,c))];
	if(v) return v;
	else if(a<=0||b<=0||c<=0) return 1;
	else if(a>20||b>20||c>20) return v = w(20,20,20);
	else if(a<b&&b<c) return v = w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
	return v = w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
}

int main() {
	std::ios::sync_with_stdio(false);
	ll a,b,c;
	while(cin >> a >> b >> c) {
		if(a==-1&&b==-1&&c==-1) break;
		cout << "w(" << a << ", " << b << ", " << c << ")";
		cout << " = "<< w(a,b,c) << endl;
	}
	return 0;
}
