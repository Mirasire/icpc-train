#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1e6+100;
typedef long long int ll;
ll arr[maxn]; //save the tree
ll n,m;

inline bool legal(ll h) {
    ll sum = 0;
    for(int i=0; i<n; i++) sum += arr[i] > h? arr[i]-h : 0;
    return sum >= m;
}

inline ll binary_srearch(ll val) {
    ll l = 0,r = val+1,mid,ans;
    while(l+1 < r) {
        mid = (l+r)>>1;
        if(legal(mid)) l = mid;
        else r = mid;
    }
    return l;
}

int main() {
    scanf("%lld%lld",&n,&m);
    for(int i=0; i<n; i++) scanf("%lld",arr+i);
    printf("%lld",binary_srearch(maxn));
    return 0;
}