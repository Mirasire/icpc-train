#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 30;
typedef long long int ll;
bool vis[maxn];
ll v[maxn][maxn],n,N;
ll MAX = 0;

void dfs(ll index,ll sum,ll times) {
    if(times > n) return;
    if(index == n) {
        MAX = max(MAX,sum);
        return;
    }
    if(vis[index] == 0){
        for(ll i=0; i<N; i++) {
            if(i != index && !vis[i]) {
                vis[index] = vis[i] = 1;
                dfs(index+1,sum+v[index][i],times+1);
                vis[index] = vis[i] = 0;
            }
        }
    } else 
        dfs(index+1,sum,times);
    return;
}


int main() {
    scanf("%lld",&n);
    N = 2*n;
    for(ll i=0; i<N; i++)
        for(ll j=0; j<N; j++)
            scanf("%lld",&v[i][j]);
    dfs(0,0,0);
    printf("%lld\n",MAX);
    return 0;
}
