#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int maxn = 1e7+10;
bool isP[maxn];
int p[maxn],cnt;

void ErGetPrime() {
	isP[0]=isP[1]=1;
	for(int i=2; i<maxn; i++) {
		if(!isP[i]) p[cnt++]=i;
		for(int j=0; j<cnt&&(i*p[j]<maxn); j++) {
			isP[i*p[j]]=1;
			if(!(i%p[j])) break;
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	int n,m,k;
	cin >> n >> m;
	ErGetPrime();
	while(m--) {
		cin >> k;
		cout << (isP[k]? "No\n" : "Yes\n");
	}
	return 0;
}
