#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <limits.h>
using namespace std;

typedef long long int ll;
const ll maxn = 1e8+100;
int arr[maxn];

int main() {
	int n,m,tmp,i;
	int ed1,ed2;
	ll Max,ans=INT64_MAX;
	scanf("%d%d",&m,&n);
	for(int i=0; i<m; i++) {
		scanf("%d",&tmp);
		arr[tmp]++;
	}
	sort(arr+1,arr+1+n);
	ll dd = (n+1)/2;
	for(int i=dd,j=0; i<=n; i++,j++) {
		i = (n+1-j)/2+j;
		if(i>n) break;
		Max = arr[n];
		ed2 = (n-j)/2;
		int p=1,q=n-j;
		//cout << "i= " << i << " p= " << p << " " << "q = " << q << endl;
		for(; p<=ed2;p++,q--) Max = max(Max,(ll)arr[p]+(ll)arr[q]);
		//cout << "Max--> " << Max << endl;
		ans = min(ans,Max*i);
		//cout << "ans = " << ans << endl;
	}
	printf("%lld",ans);
	return 0;
}
