#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

vector<int> getNext(String s) {
	int n = s.size();
	vector<int> pi(n);
	for(int i=1; i<n; i++) {
		int j = pi[i-1];
		while(j>0 && s[i] != s[j]) j = pi[j-1];
		if(s[i] == s[j]) j++;
		p[i] = j;
	}
}

int main() {
	return 0;
}
