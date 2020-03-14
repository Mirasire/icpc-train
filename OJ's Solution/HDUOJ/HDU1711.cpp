#include <bits/stdc++.h>
using namespace std;

const int Amaxn=1e6+100,Bmaxn=1e4+100;
int a[Amaxn],b[Bmaxn],nxt[Bmaxn];
int sa,sb;
void getNxt() {
	int i=0,j=-1,ed=sb-1;
	nxt[0]=-1;
	while(i<ed) {
		if(b[i]==b[j] || j==-1) {
			i++,j++;
			if(b[j]!=b[i]) nxt[i]=j;
			else nxt[i]=nxt[j];
		} else {
			j=nxt[j];
		}
	}
}
int kmp() {
	getNxt();
	int i=0,j=0;
	while(i<sa) {
		//WA_REASON: if the macthing is in the last char It will pass
		//if(j==sb) return i-j+1;
		if(a[i]==b[j] || j==-1) i++,j++;
		else j=nxt[j];
		if(j==sb) return i-j+1;
	}
	return -1;
}

int main() {
	std::ios::sync_with_stdio(false);
	int m;
	cin >> m;
	while(m--) { 
		cin >> sa >> sb;
		for(int i=0; i<sa; i++) cin >> a[i];
		for(int i=0; i<sb; i++) cin >> b[i];
		cout << kmp() << endl;
	}
	return 0;
}
