#include <bits/stdc++.h>
using namespace std;

void flip(int i,string& str) {
	if(str[i]=='B') str[i] = 'W';
	else str[i] = 'B';

	if(str[i+1]=='B') str[i+1] = 'W';
	else str[i+1] = 'B';
}

void prt(vector<int>& arr) {
	cout << arr.size() << endl;
	for(int num: arr) {
		cout << num << " ";
	}
	cout << endl;
}

int main() {
	vector<int> ans1,ans2;
	int n;
	string str;
	cin >> n >> str;
	int size = str.size();
	string tstr1,tstr2;
	tstr1 = 'B'+str;
	tstr2 = 'W'+str;
	bool f1,f2;
	f1 = f2 = 1;
	for(int i=1; i<size; i++) {
		if(tstr1[i] != 'B') {
			flip(i,tstr1);
			ans1.push_back(i);
		}
	}
	if(tstr1[size] != 'B') f1 = 0;

	for(int i=1; i<size; i++) {
		if(tstr2[i] != 'W') {
			flip(i,tstr2);
			ans2.push_back(i);
		}
	}
	if(tstr2[size] != 'W') f2 = 0;

	if(!f1&&!f2) {
		//cout << 1 << endl;
		cout << -1 << endl;
	} else if(f1&&f2) {
		//cout << 2 << endl;
		if(ans1.size() < ans2.size()) prt(ans1);
		else prt(ans2);
	} else if(f1) {
		//cout << 3 << endl;
		prt(ans1);
	} else {
		//cout << 4 << endl;
		prt(ans2);
	}
	return 0;
}
