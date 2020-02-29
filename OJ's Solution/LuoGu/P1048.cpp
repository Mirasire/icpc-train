//0|1背包
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3+100;
int dp[maxn],c[maxn],v[maxn];
int T,M;

int main() {
    scanf("%d%d",&T,&M);
    for(int i=1; i<=M; i++) scanf("%d%d",c+i,v+i);
    for(int k=1; k<=M; k++) {
        for(int i=T; i>=c[k]; i--) dp[i] = max(dp[i],dp[i-c[k]]+v[k]);
    }
    printf("%d\n",dp[T]);
    return 0;
}