#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int maxn = 1e5+100;
int a[maxn],n;

int main() {
    int sum  = 0;
    scanf("%d",n);
    for(int i=0; i<n; i++) {
        scanf("%d",a+i);
        sum += a[i];
    }
    if(sum==1) prinf("-1\n");
    else if(sum&1) {

    } else {

    }
    return 0;
}