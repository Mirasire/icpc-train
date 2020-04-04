#include <algorithm>
#include <string>
#include <queue>
#include <iostream>
using namespace std;

const int maxn = 1000030;
string p;
int nxt[maxn];
void getNxt(int n) {
	int i=0,j=-1;
	nxt[0]=-1;
	while(i<n) {
		if(j==-1 || p[i]==p[j]) {
			i++,j++;
			nxt[i]=j;
		} else j=nxt[j];
	}
}

void getAns(int n) {
	int j=nxt[n];
	queue<int> lans;
	while(j!=-1) {
		lans.push(j);
		j=nxt[j];
	}
	int k=lans.size();
	cout << k << endl;
	if(k) {
		cout << (n-lans.front());
		lans.pop();
	}
	while(!lans.empty()) {
		cout << " " << (n-lans.front());
		lans.pop();
	}
	cout << endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	int t,n,kase=0;
	cin >> t;
	while(t--) {
		cout << "Case #" << ++kase <<": ";
		cin >> p;
		n=p.size();
		getNxt(n);
		//for(int i=0; i<=n; i++) cout << nxt[i] << " ";
		//cout << endl;
		getAns(n);
	}
	return 0;
}
