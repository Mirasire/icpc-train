#include <iostream>
#include <cstdio>
using namespace std;

const int maxn = 5e4+100;
int f[maxn*3],n,k,x,y,d;

int fi(int id){
    int t1,t2 = id;
    while(id != f[id]) id = f[id];
    while(t2 != id) {
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
}

int main(){
    freopen("in","r",stdin);
    scanf("%d%d",&n,&k);
    int ed = n*3,cnt = 0;
    for(int i=0; i<=ed; i++) f[i] = i; 
    while(k--){
        scanf("%d%d%d",&d,&x,&y);
        if(x > n || y > n){
            cnt++;
            continue;
        }
        if(d==1) {
            if(fi(x) == fi(y+n) || fi(x) == fi(y+2*n)) cnt++;
            else {
                unite(x,y);
                unite(x + n,y + n);
                unite(x + 2*n,y + 2*n);
            }
        } else if(d==2) {
            if(x == y) cnt++;
            else if(fi(x) == fi(y) || fi(x) == fi(y+2*n)) cnt++;
            else {
                unite(x, y + n);
                unite(x + n, y + 2*n);
                unite(x + 2*n, y);
            }
        }
    }
    printf("%d",cnt);
    return 0;
}
    

