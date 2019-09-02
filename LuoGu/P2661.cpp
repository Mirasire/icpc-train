#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <limits.h>
using namespace std;

const int maxn = 2e5+100;
int nxt[maxn],st,out;

void dfs(int i,int sum) {
    if(i==0) return;
    if(i==st) {
        out = min(out,sum);
        return;
    } else if(nxt[i] != 0) dfs(nxt[i],sum+1);
}

int main () {
    int k,nx;
    scanf("%d",&k);
    for(int i=1; i<=k; i++) {
        scanf("%d",&nx);
        nxt[i] = nx;
    }
    out = INT_MAX;
    for(int i=1; i<=k; i++) {
        st = i;
        cout << nxt[i] << endl;
        dfs(nxt[i],1);
    }
    printf("%d\n",out);
    return 0;
}
