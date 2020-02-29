#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int maxN = 2e5+100;
int moster[maxN],s[maxN],p[maxN];
int bst[maxN];

int main() {
	int t,n,m,i;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		memset(bst,0,sizeof(int)*(n+1));
		for(i=0; i<n; i++) scanf("%d",moster+i);
		scanf("%d",&m);
		for(i=0; i<m; i++) {
			scanf("%d%d",p+i,s+i);
			bst[s[i]] = max(p[i],bst[s[i]]);
		}
		for(i=n-1; i>=0; i--) bst[i] = max(bst[i],bst[i+1]); //bst为耐力为i的最大攻击力
		int pos = 0;
		bool ok = 1;
		int day = 0;
		while(pos < n) {
			day++;
			int m=0;
			int npos = pos;
			while(1) {
				m = max(m,moster[npos]);
				if(m > bst[npos - pos + 1]) break;
				npos++;
			}
			if(npos == pos) {
				ok = 0;
				break;
			}
			pos = npos;
		}
		if(!ok) day = -1;
		printf("%d\n",day);
	}
	return 0;
}
