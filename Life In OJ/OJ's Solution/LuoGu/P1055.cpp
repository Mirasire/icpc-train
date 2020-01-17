#include <bits/stdc++.h>
using namespace std;

int arr[20];

int main() {
	char c;
	scanf("%1d-%1d%1d%1d-%1d%1d%1d%1d%1d-%c",&arr[1],&arr[2],&arr[3],&arr[4],&arr[5],&arr[6],&arr[7],&arr[8],&arr[9],&c);
	int ans = 0;
	for(int i=1; i<=9; i++) ans+=arr[i]*i;
	ans%=11;
	if((c==(int)'X' && ans == 10) || (ans == c-'0')) { cout << "Right\n"; }
	else {
		for(int i=1; i<=9; i++) {
			cout << arr[i];
			if(i==1 | i==4 | i==9) cout << "-";
		}
		if(ans==10) cout << "X";
		else cout << (char)((int)'0'+ans);
		cout << endl;
	}
	return 0;
}
