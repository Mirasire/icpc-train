#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
#include <limits.h>
using namespace std;

typedef long long int ll;
const int maxn = 2e3+100;
ll mini[maxn][maxn],c[maxn][maxn];
ll d[maxn];

int main() {
    freopen("in","r",stdin);
    int t,n,m;
    scanf("%d",&t);
    int kase = 0;
    while(t--) {
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                scanf("%lld",c[i] + j);
                c[i][j] += c[i][j-1];
                mini[i][j] = c[i][j];
            }
        }

        for(int i=1; i<=n; i++) {
            mini[i][0] = 0;
            for(int j=m-1; j>=0; j--) {
                mini[i][j] = min(mini[i][j],mini[i][j+1]);
            }
        }

        for(int i=1; i<=m; i++) {
            scanf("%lld",d+i);
            d[i] += d[i-1];
        }
        ll ans = 0;
        for(int j=1; j<=m; j++) {
            ll sum = 0;
            ll minn = INT64_MAX;
            for(int i=1; i<=n; i++) {
                sum += mini[i][j];
                minn = min(minn,c[i][j] - mini[i][j]);
            }

            sum += minn;
            ans = max(ans,d[j] - sum);
        }
        printf("Case #%d: %lld\n",++kase,ans);
    }
    return 0;
}
