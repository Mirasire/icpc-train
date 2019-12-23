//AC
#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+100;
string str[maxn];
map<string,bool> app;
vector<int> ans;

int main() {
	std::ios::sync_with_stdio(false);
	int t,n;
	int str01,str10,str00,str11;
	cin >> t;
	while(t--) {
		app.clear();
		ans.clear();
		str10 = str01 = str00 = str11 = 0;
		cin >> n;
		for(int i=1; i<=n; i++) {
			cin >> str[i];
			if(str[i][0]=='0'&&str[i].back()=='1') str01++;
			else if(str[i][0]=='1'&&str[i].back()=='0') str10++;
			else if(str[i][0]=='0'&&str[i].back()=='0') str00++;
			else if(str[i][0]=='1'&&str[i].back()=='1') str11++;
			app[str[i]] = 1;
		}
		if(str00&&str11&&!str01&&!str10) {
			cout << "-1\n";
			continue;
		} else if(abs(str10-str01)<=1) {
			cout << "0\n";
			continue;
		} else if(str01 > str10 + 1) {
			int res = (str10+str01)/2-str10;
			cout << res << endl;
			for(int i=1; res&&i<=n; i++) {
				if(str[i][0]=='0'&&str[i].back()=='1') {
					reverse(str[i].begin(),str[i].end());
					if(!app[str[i]]) {
						ans.push_back(i);
						res--;
					}
				}
			}
			for(int idx: ans) cout << idx << " ";
			cout << endl;
		} else if(str10 > str01 + 1) {
			int res = (str10+str01)/2-str01;
			cout << res << endl;
			for(int i=1; res&&i<=n; i++) {
				if(str[i][0]=='1'&&str[i].back()=='0') {
					reverse(str[i].begin(),str[i].end());
					if(!app[str[i]]) {
						ans.push_back(i);
						res--;
					}
				}
			}
			for(int idx: ans) cout << idx << " ";
		}
	}
	return 0;
}
