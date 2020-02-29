#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(),v.end()

void prt(string& t,int sta) {
	if(!t.size()) return;
	int idx = 0;
	while(idx < t.size() && t[idx] == '0') idx++;
	if(idx == t.size()) {
		cout << 0;
		return;
	}
	if(sta == 2) {
		idx = t.size()-1;
		while(idx >=0 && t[idx] == '0') idx--;
		for(int i=0; i<=idx; i++) cout << t[i];
	}
	else {
		while(idx < t.size()) {
			cout << t[idx];
			idx++;
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	string str,tmp="";
	cin >> str;
	int sta = 1;
	for(int i=0; i<str.size(); i++) {
		if(str[i]=='.' || str[i]=='/' || str[i]=='%') {
			prt(tmp,sta);
			if(str[i] == '.') sta = 2;
			cout << str[i];
			tmp = "";
		} else {
			tmp = str[i]+tmp;
		}
	}
	prt(tmp,sta);
	return 0;
}
