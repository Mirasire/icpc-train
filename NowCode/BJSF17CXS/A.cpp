#include <iostream>
#include <cstdio>
#include <algorithm>
#include <limits.h>
using namespace std;

int main(){
    int n,p;
    scanf("%d",&n);
    while(n--){
        int Min = INT_MAX,sum=0;
        for(int i=0; i<23; i++){
            scanf("%d",&p);
            Min = min(Min,p);
            sum+=p;
        }
        printf("%d\n",sum*Min);
    }
    return 0;
}
