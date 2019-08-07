#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxnn = 1e4+10;
bool vis[maxnn];

int main() {
    int n,l,r,i,k;
    scanf("%d%d",&n,&k);
    while(k--) {
        scanf("%d%d",&l,&r);
        for(i=l; i<=r; i++) vis[i] = 1;
    }
    int cnt = 0;
    for(int i=0; i<=n; i++) if(!vis[i]) cnt++;
    printf("%d\n",cnt);
    return 0;
}
