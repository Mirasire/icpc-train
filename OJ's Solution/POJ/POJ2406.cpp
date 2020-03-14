#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1000100;
int nxt[maxn];
char p[maxn];
int n;

void getNxt() {
	int i=0,j=-1;
	nxt[0]=-1;
	while(i<n) {
		if(j==-1||p[i]==p[j]) {
			i++,j++;
			nxt[i]=j;
		} else {
			j=nxt[j];
		}
	}
}
void slove() {
	getNxt();
	int cir=n-nxt[n];
	if(cir!=n&&!(n%cir)) printf("%d\n",n/cir);
	else printf("1\n");
}

int main() {
	while(scanf(" %s",p)!=EOF) {
		if(p[0]=='.'&&p[1]=='\0') break;
		n=strlen(p);
		slove();
	}
	return 0;
}
