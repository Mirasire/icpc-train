//WA
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; 
	cin >> t;
	while(t--) {
		string str;
		cin >> str;
		str = str + "ABCD";
		vector<int> ans;
		int i=-1,size = str.size();
		string ms = "";
		while(i<size) {
			if(ms.size() < 3) {
				i++;
				ms = ms+str[i];
			} else {
				if(ms == "one") {
					ans.push_back(i);
					ms = "";
				} else if(ms == "two") {
					if(str[i+1]=='n' && str[i+2]=='e' && str[i+3] != 'e') {
						ans.push_back(i+1);
						ms = "";
					} else {
						ans.push_back(i);
						ms = "o";
					}
				} else {
					string tp = ms;
					ms="";
					for(int i=1; i<3; i++) ms = ms + tp[i];
				}
			}
		}
		cout << ans.size() << endl;
		for(int num: ans) cout << num << " ";
		cout << endl;
	}
	return 0;
}
