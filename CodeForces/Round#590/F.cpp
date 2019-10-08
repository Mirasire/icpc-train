#include <iostream>
#include <map>
#include <string>
using namespace std;

typedef long long ll;

int main() {
	string str;
	map<char,bool> app;
	cin >> str;
	ll end = str.size();
	ll ans = 0;
	for(int i=0; i<end; i++) {
		if(!app[str[i]]) {
			app[str[i]]  = 1;
			ans++;
		}
	}
	cout << ans;
}

