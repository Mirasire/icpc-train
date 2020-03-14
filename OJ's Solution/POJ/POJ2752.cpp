#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

const int maxn = 4e5+100;
int nxt[maxn];
char p[maxn];
int n;

void getNxt() {
	int i=0,j=-1;
	nxt[0]=-1;
	while(i<n) {
		if(j==-1 || p[i]==p[j]) {
			i++,j++;
			nxt[i]=j;
		} else {
			j=nxt[j];
		}
	}
}


void slove() {
	int i=n;
	getNxt();
	stack<int> ans;
	while(i!=0&&i!=-1) {
		ans.push(i);
		i=nxt[i];
	}
	while(!ans.empty()) {
		printf("%d ",ans.top());
		ans.pop();
	}
	putchar('\n');
}

int main() {
	//std::ios::sync_with_stdio(false);
	while(scanf(" %s",p)!=EOF) {
		n=strlen(p);
		slove();
	}
	return 0;
}
