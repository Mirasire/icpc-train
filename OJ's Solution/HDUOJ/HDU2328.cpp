#include <bits/stdc++.h>
using namespace std;

const int maxn=4300;
int s[maxn],n,nxt[300];
string t[maxn];

void getNxt(string p,int ps) {
	int i=0,j=-1;
	nxt[0]=-1;
	while(i<ps) {
			if(j==-1||p[i]==p[j]) {
						i++,j++;
						nxt[i] = (p[i]==p[j])? nxt[j] : j;
					} else j=nxt[j];
		}
}

bool kmp(string tt,int ts,string p,int ps) {
	int i=0,j=0;
	while(i<ts&&j<ps) {
			if(j==-1 || tt[i]==p[j]) i++,j++;
			else j=nxt[j];
		}
	return (j==ps);
}

bool check(string p,int ps) {
	for(int i=1; i<n; i++)
		if(!kmp(t[i],s[i],p,ps)) return 0;
	return 1;
}

void slove() {
	int as=0;
	string ans="",p;
	for(int i=0; i<s[0]; i++) {
			for(int j=s[0]-i; j>=as; j--) {
						p = t[0].substr(i,j);
						getNxt(p,j);
						if(check(p,j) && ((j>as)||(j==as&&p<ans))) as=j,ans=p;
					}
		}
	if(!as) cout << "IDENTITY LOST";
	else cout << ans;
	cout << endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	while(cin >> n) {
			if(!n) return 0;
			for(int i=0; i<n; i++) {
						cin >> t[i];
						s[i]=t[i].size();
					}
			slove();
		}
	return 0;
}
