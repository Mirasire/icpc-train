#include <stdio.h>

const int maxn = 1e3+100;
int f[maxn];

int fi(int id){
    int t1,t2= id;
    while(f[id] != id) id = f[id];
    while(t2 != id){
        t1 = f[t2];
        f[t2] = id;
        t2 = t1;
    }
    return id;
}

void unite(int a,int b){
    int r_a = fi(a);
    int r_b = fi(b);
    if(r_a != r_b) f[r_a] = r_b;
    return;
}

int main(){
    freopen("in","r",stdin);
    int n;
    scanf("%d",&n);
    while(n--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0; i<=n; i++) f[i] = i;
        while(m--){
            int a,b;
            scanf("%d%d",&a,&b);
            unite(a,b);
        }
        int cnt = 0;
        for(int i=1; i<=n; i++) if(i == f[i]) cnt++;
        printf("%d\n",cnt);
    }
    return 0;
}


