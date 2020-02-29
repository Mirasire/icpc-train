#include <bits/stdc++.h>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int n;
	string str;
	cin >> n >> str;
	for(int i=0; i<str.size(); i++) cout << (char)(((int)str[i]-(int)'a'+n)%26+(int)'a');
	cout << endl;
	return 0;
}
