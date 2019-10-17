#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 102;
int fish[maxn];

int main() {
    int k,j,i,ans;
    scanf("%d",&k);
    for(i=0; i<k; i++) {
        scanf("%d",fish+i);
    }
    for(i=0; i<k; i++) {
        ans = 0; 
        for(j=0; j<i; j++) if(fish[j] < fish[i]) ans++;
        printf("%d ",ans);
    }
    return 0;
}
