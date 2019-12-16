//AC
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		string str;
		cin >> str;
		vector<int> ans;
		int i=0;
		while((i = str.find("twone",i)) != string::npos) {
			ans.push_back(i+3);
			str[i+2] = 'M';
		}
		i = 0;
		while((i = str.find("two",i)) != string::npos) {
			ans.push_back(i+2);
			str[i+1] = 'M';
		}
		i = 0;
		while((i = str.find("one",i)) != string::npos) {
			ans.push_back(i+2);
			str[i+1] = 'M';
		}
		cout << ans.size() << endl;
		for(int num: ans) cout << num << " ";
		cout << endl;
	}
	return 0;
}
