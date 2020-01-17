#include <bits/stdc++.h>
using namespace std;

const int maxn = 120;
int cnt[30];

int main() {
	std::ios::sync_with_stdio(false);
	string str;
	int mx = 0;
	for(int i=0; i<4; i++) {
		getline(cin,str);
		for(int i=0; i<str.size(); i++) {
			if(str[i] >= 'A' && str[i] <= 'Z') {
				int key = str[i]-'A';
				cnt[key]++;
				mx = max(cnt[key],mx);
			}
		}
	}
	for(int i=0; i<mx; i++) {
		for(int j=0; j<26; j++) {
			if(i >= mx-cnt[j]) cout << '*';
			else cout << ' '; 
			if(j<25) cout << ' ';
			else cout << endl;
		}
	}
	for(int i=0; i<26; i++) { 
		cout << (char)('A'+i); 
		if(i<25) cout << ' ';
		else cout << endl;
	}
	return 0;
}
