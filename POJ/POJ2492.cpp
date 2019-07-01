#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

const int maxn = 2e3+100;
int f[maxn*2], n, x, y, k;

int fi(int id){
    int t1,t2 = id;
    while(f[id] != id) id = f[id];
    while(t2 != id){
        t1 = f[t2];
        f[t2] = id;
        t2 = t1;
    }
    return id;
}

void unite(int a,int b) {
    int r_a = fi(a);
    int r_b = fi(b);
    if(r_a != r_b) f[r_a] = r_b;
    return;
}

int main(){
    freopen("in","r",stdin);
    int m,kase=0,end;
    scanf("%d",&m);
    while(m--){
        bool flag = 1;
        printf("Scenario #%d:\n",++kase);
        scanf("%d%d",&n,&k);
        end = 2*n;
        for(int i=0; i <= end; i++) f[i] = i;
        while(k--){
            scanf("%d%d",&x,&y);
            if(flag) {
                if(fi(x) != fi(y) && fi(x+n) != fi(y+n)) {
                    unite(x,y+n);
                    unite(x+n,y);
                } else {
                    flag = 0;
                }
            }
        }
        if(flag) printf("No suspicious bugs found!\n\n");
        else printf("Suspicious bugs found!\n\n");
    }
    return 0;
}
