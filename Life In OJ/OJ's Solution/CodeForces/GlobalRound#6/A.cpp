#include <bits/stdc++.h>
using namespace std;

const int maxn = 15;
int ct[maxn];

int main() {
	std::ios::sync_with_stdio(false);
	int  n;
	cin >> n;
	while(n--) {
		memset(ct,0,sizeof(ct));
		string str;
		cin >> str;
		for(int i=0; i<str.size(); i++) {
			ct[str[i]-'0']++;
		}
		int k=0;
		for(int i=0; i<9; i++) k += ct[i]*i;
		if(ct[0]>0) {
			ct[0]--;
			if(!(k%3) && (ct[0] || ct[2] || ct[4] || ct[6] || ct[8])) {
				cout << "red\n";
			} else {
				cout << "cyan\n";
			}
		} else {
			cout << "cyan\n";
		}
	}
	return 0;
}
