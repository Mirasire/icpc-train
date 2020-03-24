#include <bits/stdc++.h>
using namespace std;

const int maxn=5e4+100;
string p,t;
int nxt[maxn],n;

void getNex() {
	int i=0,j=-1;
	nxt[0]=-1;
	while(i<n) {
		if(j==-1||p[i]==p[j]) {
			i++,j++;
			nxt[i]=j;
		} else {
			j=nxt[j];
		}
	}
}

int main() {
	int _n;
	int i,j;
	while( cin >> p) {
		cin >> t;
		i=j=0;
		n=p.size();
		_n=t.size();
		getNex();
		while(i<_n) {
			if(j==n) j=nxt[j];
			if(j==-1||t[i]==p[j]) i++,j++;
			else j=nxt[j];
		}
		if(j>0) cout << p.substr(0,j) << " " << j << endl;
		else cout << 0 << endl;
	}
	return 0;
}
