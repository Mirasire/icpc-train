#include <iostream>
#include <cstring>
#include <map>
using namespace std;

map<char,int> mp;

int n[12];
string add1 = " 1",add2 = " 0";

//zero
//one
int main() {
	int t;
	mp['z'] = 1;
	mp['e'] = 2;
	mp['r'] = 3;
	mp['o'] = 4;
	mp['n'] = 5;
	string str;
	string out;
	cin >> t >> str;
	for(int i=0; i<t; i++) {
		n[mp[str[i]]]++;
	}
	for(int i=0; i<n[5]; i++) 
		if(out.empty()) {
			out = "1";
		} 
		else out += add1;
	for(int i=0; i<n[1]; i++) 
		if(out.empty()) {
			out = "0";
		} 
		else out += add2;
	cout << out;
	return 0;
}
