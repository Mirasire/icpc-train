#include <bits/stdc++.h>
using namespace std;


int main() {
	string bsc;
	int ans = 0;
	cin >> bsc;
	int end = bsc.size()/2;
	for(int i=0,j=bsc.size()-1; i<end; i++,j--) {
		if(bsc[i]!=bsc[j]) ans++;
	}
	printf("%d\n",ans);
	return 0;
}
