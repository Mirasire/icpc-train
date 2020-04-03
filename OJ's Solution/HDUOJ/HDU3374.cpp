#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1000200;
char sec[maxn];
int nxt[maxn];
int n;

void getNxt() {
	int i=0,j=-1;
	nxt[0]=-1;
	while(i<n) {
		if(j==-1 || sec[i]==sec[j]) {
			i++,j++;
			nxt[i]=j;
		} else j = nxt[j];
	}
}

int getMinRepet() {
	int i=0,j=1,k=0;
	while(i<n&&j<n&&k<n) {
		if(sec[(i+k)%n]==sec[(j+k)%n])	k++;
		else {
			sec[(i+k)%n]>sec[(j+k)%n]? i+=k+1 : j+=k+1;
			k=0;
			if(i==j) j++;
		}
	}
	return min(i,j);
}

int getMaxRepet() {
	int i=0,j=1,k=0;
	while(i<n&&j<n&&k<n) {
		if(sec[(i+k)%n]==sec[(j+k)%n])	k++;
		else {
			sec[(i+k)%n]>sec[(j+k)%n]? j+=k+1 : i+=k+1;
			k=0;
			if(i==j) j++;
		}
	}
	return min(i,j);
}

int main() {
	int minRep,maxRep,rep,ans;
	while(scanf("%s",sec)!=EOF) {
		n=strlen(sec);
		getNxt();
		minRep=getMinRepet();
		maxRep=getMaxRepet();
		rep=n-nxt[n];
		ans = n%rep? 1 : n/rep;
		printf("%d %d %d %d\n",minRep+1,ans,maxRep+1,ans);
	}
}
