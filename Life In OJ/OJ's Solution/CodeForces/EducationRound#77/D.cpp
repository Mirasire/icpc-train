#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

#define debug(x) printf(#x " = %d\n",x);
const int maxn = 2e5+100;
int soldier[maxn],m,n,k,t;

struct TRAP {
	int l,r,d;
	bool operator < (const TRAP& o) {
		return o.l==l? r < o.r : l < o.l;
	}
} trap[maxn];

bool cmp(const int& a,const int& b) { return a>b; }

bool check(int id) {
    int key = soldier[id];
    int pre,end,sum = 0;
    pre = end = 0;
    for(int i=0; i<=k; i++) {
        TRAP& now = trap[i];
        if(now.d > key) {
            if(now.l <= end) end = max(end,now.r);
            else {
                sum += end - pre;
                pre = now.l;
                end = now.r;
            }
        }
    }
    // debug(id);
    // debug(sum);
    return sum*2+(n+1) <= t;
}

//二分！！需要着重学习
int binary_search() {
    int l = 0, r = m+1,mid,ans;
    while(l+1<r) {
        mid = (l+r)>>1;
        if(check(mid)) l = mid;
        else r = mid;
    }
    return l;
}

int main() {
	scanf("%d%d%d%d",&m,&n,&k,&t);
	for(int i=1; i<=m; i++) scanf("%d",&soldier[i]);
	sort(soldier+1,soldier+m+1,cmp);
    for(int i=0; i<k; i++) {
        scanf("%d%d%d",&trap[i].l,&trap[i].r,&trap[i].d);
        trap[i].l--;
    }
    trap[k].l = trap[k].r = trap[k].d = maxn;
    sort(trap,trap+k+1);
    printf("%d\n",binary_search());
	return 0;
}
