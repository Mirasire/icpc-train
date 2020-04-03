#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

const int maxn = 2e5+100,MOD=10007;
char p[maxn];
int z[maxn];
void init(int n) { for(int i=0; i<=n; i++) z[i]=0; }

void getZFunc(int n) {
	int l=0,r=0;
	ll ans=n%MOD;
	for(int i=1; i<n; i++) {
			if(i<=r) z[i]=min(r-i+1,z[i-l]);
			while(i+z[i]<n&&p[z[i]]==p[i+z[i]]) z[i]++;
			ans=(ans+z[i])%MOD;
			if(i+z[i]-1>r) l=i,r=i+z[i]-1;
		}
	printf("%lld\n",ans);
}

int main() {
	int t,n;
	scanf("%d",&t);
	while(t--) {
			scanf("%d",&n);
			init(n);
			scanf("%s",p);
			getZFunc(n);
		}
	return 0;
}
