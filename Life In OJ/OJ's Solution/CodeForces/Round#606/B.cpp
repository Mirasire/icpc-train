#include <bits/stdc++.h>
using namespace std;

const  int maxn =  2e5+100;
typedef long long int ll;
ll arr[maxn];

int main() {
	int t,n;
	ll tp;
	scanf("%d",&t);
	while(t--) {
		map<ll,bool> app;
		long long int ans = 0;
		int cnt = 0;
		scanf("%d",&n);
		while(n--) {
			scanf("%lld",&tp);
			if(tp%2==0 && !app[tp]) {
				arr[cnt++] = tp;
				app[tp]=1;
			}
		}
		sort(arr,arr+cnt);
		for(int i=cnt-1; i>=0; i--) {
			while(arr[i]%2==0) {
				arr[i]>>=1;
				ans++;
				if(app[arr[i]]) break;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
