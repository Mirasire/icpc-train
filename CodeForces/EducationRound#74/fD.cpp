#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const long long int MAXSIZE = 3e5+100;
char str[MAXSIZE];

int main() {
	long long int n,sub = 0;
	long long int i,j;
	scanf("%lld",&n);
	scanf("%s",str);
	for(i=0; i<n; i++) {
		if(str[i] == 'A') {
			for(j=i-1; j>=0; j--) {
				if(str[j]=='B') sub++;
				else break;
			}
			for(j=i+1; j<n; j++) {
				if(str[j]=='B') sub++;
				else break;
			}
		}
		else {
			for(j=i-1; j>=0; j--) {
				if(str[j]=='A') sub++;
				else break;
			}
			for(j=i+1; j<n; j++) {
				if(str[j]=='A') sub++;
				else break;
			}
		}
	}
	for(long long int i=1; i<n; i++) 
		if(str[i] != str[i-1]) sub--; //...BA..，.......AB.....
	printf("%lld",n*(n-1)/2 - sub);
	return 0;
}
