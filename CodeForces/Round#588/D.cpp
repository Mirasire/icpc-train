#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

typedef long long int ll;
map<ll,ll> cnt;
bool vis[7100];
vector<ll> a,b,ans;
ll res;

int main() {
    res = 0;
    int n;
    ll tmp;
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        scanf("%lld",&tmp);
        cnt[tmp]++;
        a.push_back(tmp);
    }
    for(int i=0; i<n; i++) {
        scanf("%lld",&tmp);
        b.push_back(tmp);
        if(cnt[a[i]] >= 2) {
            vis[i] = 1;
            ans.push_back(a[i]);
            res+=tmp;
        }
    }
    for(int i=0; i<n; i++) {
        if(!vis[i]) {
            int end = ans.size();
            for(int j=0; j<end; j++) {
                if(a[i] < ans[j] && (a[i] | ans[j]) == ans[j]) {
                    ans.push_back(a[i]);
                    res += b[i];
                    break;
                }
            }
        }
    }
    printf("%lld\n",res);
    return 0;
}
