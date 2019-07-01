#include <iostream>
#include <stdio.h>
using namespace std;

const int maxn = 2e5+100;
int f[maxn],v[maxn];
int cnt;

int fi(int id){
    if(f[id] != id){
        int per = f[id];
        f[id] = fi(per);
        v[id] += v[per];
    }
    return f[id];
}

void unite(int a,int b,int c){
    int r_a = fi(a);
    int r_b = fi(b);
    if(r_a != r_b) {
        f[r_a] = r_b;
        v[r_a] = -v[a] + v[b] + c;
    } else {
        cnt += (v[a] - v[b] != c);
    }
    return;
}

int main(){
    int n,m,a,b,c;
    //freopen("in","r",stdin);
    while(scanf("%d%d",&n,&m) != EOF){
        cnt = 0;
        for(int i=0; i<=n; i++) f[i] = i,v[i] = 0;
        while(m--){
            scanf("%d%d%d",&a,&b,&c);
            a--;
            unite(a,b,c);
        }
        printf("%d\n",cnt);
    }
    return 0;
}
