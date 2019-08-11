//After Contest
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
    int k,t;
    scanf("%d",&k);
    long long int a,b,c;
    while(k--) {
        scanf("%d",&t);
        if(t>2) {
            while(t-->=0) scanf("%lld",&a);
            printf("No\n");
        } 
        else if(t<2) {
            while(t-->=0) scanf("%lld",&a);
            printf("Yes\n");
        }
        else {
            scanf("%lld%lld%lld",&a,&b,&c);
            long long int delte = b*b - 4*a*c;
            if(delte >= 0) printf("No\n");
            else printf("Yes\n");
        }
    }
    return 0;
}
