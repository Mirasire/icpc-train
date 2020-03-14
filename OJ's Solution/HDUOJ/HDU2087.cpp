#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int nxt[10020];
void getNext(string p) {
	int i=0,j=-1,end=p.size();
	nxt[0]=-1;
	while(i<end) {
		if(j==-1||p[i]==p[j]) {
			i++,j++;
			nxt[i]=(p[i]==p[j]? nxt[j]: j);
		} else {
			j=nxt[j];
		}
	}
}
int kmp2(string t,string p) {
	getNext(p);
	int cnt=0;
	int st=t.size(),sp=p.size();
	if(st<sp) return 0;
	int i=0,j=0;
	while(i<st) {
		if(t[i]==p[j] || j==-1) i++,j++;
		else j=nxt[j];
		if(j==sp) {
			j=0;
			cnt++;
		}
	}
	return cnt;
}

int main() {
	std::ios::sync_with_stdio(false);
	string t,p;
	while(cin >> t) {
		if(t=="#") break;
		cin >> p;
		cout << kmp2(t,p) << endl;
	}
	return 0;
}
