#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e4+100;
bool isPrime[maxn];
int p[3000],cnt;
int ans[5];
int tar;

void erPrim() {
	cnt=0;
	for(int i=2; i<=20000; i++) {
		if(!isPrime[i]) p[cnt++] = i;
		for(int j=0; j<cnt&&(p[j]*i<20000); j++) {
			isPrime[p[j]*i]=1;
			if(!(i%p[j])) break;
		}
	}
}

bool flag=0;
void dfs(int st,int t,int sum) {
	if(flag) return;
	if(t==3 && sum==tar) {
		cout << ans[0] << " " << ans[1] << " " << ans[2];
		flag = 1;
	}
	else if(t>=3 || sum >= tar) return;
	for(int i=st; i<cnt; i++) {
		ans[t] = p[i];
		dfs(i,t+1,sum+p[i]);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	erPrim();
	cin >> tar;
	dfs(0,0,0);
	return 0;
}
