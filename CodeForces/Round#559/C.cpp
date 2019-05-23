#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int b[n],g[m];
    for(int i=0; i<n; i++) scanf("%d",b+i);
    for(int i=0; i<m; i++) scanf("%d",g+i);
    sort(b,b+n);
    sort(g,g+m);
    long long sum_b = 0, sum_g = 0 ;
    if(b[n-1] > g[0]) printf("-1\n");
    else{
        for(int i=0; i<n; i++) sum_b+=m*b[i]; 
        for(int i=0; i<m; i++) sum_g+=g[i]; 
        if(b[n-1] == g[0]){
            printf("%lld\n",sum_b + sum_g - b[n-1] * m);
        }
        else{
            printf("%lld\n",sum_b + sum_g - b[n-1] * (m - 1) - b[n-2]);
        }
    }
    return 0;
}


