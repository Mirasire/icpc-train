#include <string>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

int lletter[39];
set<char> toFind;
const int maxn = 5e5+100;
bool vis[maxn];

int main() {
	string s;
	cin >> s;
	int end = s.size();
	int mid = 0;
	char mi = s[0];
	toFind.insert(mi);
	for(int i=1; i<end; i++) {
		if(s[i] < mi) {
			mi = s[i];
			mid = i;
			vis[i] = 0;
		} else if(s[i] == mi){
			vis[i] = 0;
		} else {
			vis[i] = 1;
		}
	}
	for(int i=0; i<end; i++) {
		if(!vis[i]) 
			printf("Mike\n");
		else 
			printf("Ann\n");
	}
	return 0;
}
