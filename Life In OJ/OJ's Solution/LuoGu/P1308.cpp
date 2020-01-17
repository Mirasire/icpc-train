#include <bits/stdc++.h>
using namespace std;

bool Equal(string& a,string& b,int idx) {
	int size = a.size();
	for(int i=0; i<size; i++,idx++) {
		if(toupper(a[i])!=toupper(b[idx])) return 0;
	}
	return 1;
}

int main() {
	std::ios::sync_with_stdio(false);
	string tmp,bsc;
	getline(cin,tmp);
	getline(cin,bsc);
	int end = bsc.size();
	int cnt = 0,fi = 0;
	for(int i=0; i<end; i++) {
		if(i+tmp.size()-1 >= end) break;
		else if(i+tmp.size() == end || bsc[i+tmp.size()] == ' ') {
			if(Equal(tmp,bsc,i)) {
				if(!cnt) fi = i;
				cnt++;
			}
		}
		while(i<end && bsc[i]!=' ') i++;
	}
	if(!cnt) cout << -1 << endl;
	else cout << cnt << " " << fi << endl;
	return 0;
}
