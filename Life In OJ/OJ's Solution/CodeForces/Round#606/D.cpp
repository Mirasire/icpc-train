#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+100;
string str[maxn];
map<string,bool> app;

struct NODE {
	int l,r;
	NODE() {}
	NODE(int l,int r):l(l),r(r) {}
};

int main() {
	int t,n;
	string tmp;
	cin >> t;
	while(t--) {
		app.clear();
		cin >> n;
		int oo,ol,lo,ll;
		vector<NODE> list;
		oo = ol = lo = ll = 0;
		for(int i=0; i<n; i++) {
			cin >> str[i];
			app[str[i]] = 1;
			int c1 = str[0]-'0',c2 = str.back()-'0';
			list.push_back(c1,c2);
			if(!c1&&!c2) oo++;
			else if(c1&&c2) ll++;
			else if(c1) lo++;
			else ol++;
		}
		if(n==1) cout << "0\n\n";
		if(ll&&oo&&!lo&&!ol) cout << "-1\n";
		else if(abs(ol-lo)==1) cout << "0\n\n";
		else if(ol > lo) {
			int miner = ol - lo - 1;
			cout << miner << endl;
			for(NODE now: list) {
				if(now.l^now.r) {
					string tstr = 
				}
			}
		} else {
		}
	}
	return 0;
}
