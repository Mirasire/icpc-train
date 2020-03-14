#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int nxt[70];
int n,m;
string p;
string t[12];

void getNxt(int l) {
	int i=0,j=-1;
	nxt[0]=-1;
	while(i<l) {
		if(j==-1||p[i]==p[j]) {
			i++,j++;
			nxt[i]=(p[i]==p[j])? nxt[j] : j;
		} else {
			j=nxt[j];
		}
	}
}

bool kmp(int k,int l) {
	int i=0,j=0;
	while(i<60&&j<l) {
		if(j==-1 || t[k][i]==p[j]) i++,j++;
		else j=nxt[j];
	}
	if(j==l) return 1;
	return 0;
}

bool check(int l) {
	getNxt(l);
	for(int i=1; i<n; i++) {
		if(!kmp(i,l)) return 0;
	}
	return 1;
}

void slove() {
	//find substr
	int len;
	string ans="";
	bool flg=0;
	for(int i=0; i<60; i++) {
		len=60-i;
		for(int j=3; j<=len; j++) {
			p = t[0].substr(i,j);
			if(check(j)) {
				flg=1;
				ans = (p.size()>ans.size() || (p.size()==ans.size()&&p<ans))? p : ans;
			}
		}
	}
	if(flg) cout << ans << endl;
	else cout << "no significant commonalities\n";
}


int main() {
	std::ios::sync_with_stdio(false);
	cin >> m;
	while(m--) {
		cin >> n;
		for(int i=0; i<n; i++) cin >> t[i];
		slove();
	}
	return 0;
}
