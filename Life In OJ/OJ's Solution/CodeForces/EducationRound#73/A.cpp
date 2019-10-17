#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
 
const int maxn = 110;
int a[maxn];
 
bool cmp(const int& a,const int& b) {return a>b;}
 
int main() {
    int t,n;
    int gg = 0;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        gg = 2048;
        for(int i=0; i<n; i++) scanf("%d",a+i);
        sort(a,a+n,cmp);
        for(int i=0; i<n; i++) {
            if(gg == 0) break;
            else if(a[i] <= gg) gg-=a[i];
        }
        if(!gg) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
 
