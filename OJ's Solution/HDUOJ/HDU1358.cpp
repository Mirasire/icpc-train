#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6+100;
int nxt[maxn];
char p[maxn];

void getNxt(int n) {
	int i=0,j=-1;
	nxt[0]=-1;
	while(i<n) {
		if(j==-1||p[i]==p[j]) {
			j++,i++;
			nxt[i]=j;
		} else {
			j=nxt[j];
		}
	}
}

void slove(int n) {
	getNxt(n);
	int k,cir;
	for(int i=2; i<=n; i++) {
		k=i;
		cir=i-nxt[i];
		if(cir!=i&&!(i%cir)) printf("%d %d\n",i,i/cir);
	}
}

int main() {
	int n,kase=0;
	while(scanf("%d",&n)!=EOF) {
		if(!n) break;
		scanf(" %s",p);
		printf("Test case #%d\n",++kase);
		slove(n);
		putchar('\n');
	}
	return 0;
}
