#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+100;
char str[maxn];
int nxt[maxn];
int n;

void getNxt() {
	nxt[0]=-1;
	int i=0,j=-1;
	while(i<n) {
		if(j==-1 || str[i]==str[j]) {
			i++,j++;
			//相等代表继续失配
			nxt[i] = j;
			//nxt[i] = str[j]==str[i]? nxt[j] : j;
		} else {
			j = nxt[j];
		}
	}
}

int getAns() {
	getNxt();
	int cir = n-nxt[n];
	if(n%cir||!nxt[n]) return cir-n%cir;
	else return 0;
	//if(cir==n) return n;
	//return ceil((n*1.0)/cir)*cir-n;
}

int main() {
	//std::ios::sync_with_stdio(false);
	int t;
	scanf("%d",&t);
	while(t--) {
		scanf(" %s",str);
		n=strlen(str);
		printf("%d\n",getAns());
	}
	return 0;
}
