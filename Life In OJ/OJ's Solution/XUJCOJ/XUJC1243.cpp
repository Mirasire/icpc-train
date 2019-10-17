#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll maxn = 5e7+10;
const ll MOD = 1e6;
ll wss;
struct Node{
    int num,j;
};
Node p[130];
int ans[130];
bool cmp(Node a, Node b) {
    return a.j < b.j;
}

int main() {
    //freopen("in","r",stdin);
    int index,kase=0;
    while(scanf("%d",&index) != EOF) {
        p[kase].j = index;
        p[kase].num = kase;
        kase++;
    }
    sort(p,p+kase,cmp);
    int ii = 0;
    while(p[ii].j == 0) {
        ans[p[ii].num] = 1;
        ii++;
    } 
    wss = 1;
    for(ll i=1; i<=p[kase-1].j; i++) {
        wss = i*wss;
        while(wss%10==0) wss/=10;
        wss %= MOD;
        while(p[ii].j == i) {
            ans[p[ii].num] = wss%10;
            ii++;
        } 
        if(wss < 0) cout << -1 << endl;
    }
    for(int i=0; i<kase; i++) printf("%d\n",ans[i]);
    return 0;
}
