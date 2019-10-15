#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int main() {
	int n,size;
	int p,t,i,j;
	string str;
	cin >> n;
	while(n--) {
		p = t = -1;
		cin >> size >> str;
		for( i=0,j=1; i<size; i++,j++) {
			if(str[i]=='1') {
				p  = max(j,p);
				p  = max(size-j+1,p);
			}
		}
		if(p!=-1) cout << max(p*2,t*2) << endl;
		else cout << size << endl;
	}
	return 0;
}
