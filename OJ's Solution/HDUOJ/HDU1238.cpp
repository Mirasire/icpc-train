#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(),v.end()

const int maxn = 120;
string str[maxn];
int nxt[maxn];

void getNxt(string p,int n) {
	int i=0,j=-1;
	nxt[0]=-1;
	while(i<n) {
			if(j==-1||p[i]==p[j]) {
						i++,j++;
						nxt[i] = (p[i]==p[j])? nxt[j] : j;
					} else 
				j=nxt[j];
		}
}

bool kmp(string t,string p,int m,int n) {
	int i=0,j=0;
	while(i<m&&j<n) {
			if(j==-1||t[i]==p[j]) i++,j++;
			else j=nxt[j];
		}
	return j==n;
}

bool check(string p,int k) {
	int n=p.size();
	bool f1,f2;
	getNxt(p,n);
	for(int i=1; i<k; i++) {
			int m=str[i].size();
			f1=!kmp(str[i],p,m,n);
			reverse(all(str[i]));
			f2=!kmp(str[i],p,m,n);
			if(f1&&f2) return 0;
		}
	return 1;
}

void slove(int k) {
	int ans=0;
	int n=str[0].size();
	for(int i=0; i<n; i++) {
			for(int j=n-i; j>0; j--) {
						if(check(str[0].substr(i,j),k)) ans=max(ans,j);
					}
		}
	reverse(all(str[0]));
	for(int i=0; i<n; i++) {
			for(int j=n-i; j>0; j--) {
						if(check(str[0].substr(i,j),k)) ans=max(ans,j);
					}
		}
	cout << ans << endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	int t,k;
	cin >> t;
	while(t--) {
			cin >> k;
			for(int i=0; i<k; i++) cin >> str[i];
			slove(k);
		}
	return 0;
}
