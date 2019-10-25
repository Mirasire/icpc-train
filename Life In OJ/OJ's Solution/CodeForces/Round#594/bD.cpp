#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int maxn = 120;
char str[maxn];
int parr[maxn];

int main() {
	int n,i,j;
	scanf("%d",&n);
	scanf(" %s",str+1);
	int res=0,oi=1,oj=1;
	for(i=1; i<=n; i++) {
		for(j=i+1; j<=n; j++) {
			swap(str[i],str[j]);
			int st = 0, c = 0, now = 0;
			for(int k=1; k<=n; k++) {
				str[k]=='('? st++ : st-- ;
				if(st == now) c++;
				if(st < now) c=1,now = st;
			}
			if(!st&&c>res) res=c,oi=i,oj=j;
			swap(str[i],str[j]);
		}
	}
	printf("%d\n%d %d",res,oi,oj);
	return 0;
}
