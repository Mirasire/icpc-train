#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1e6+100;
int a[maxn];

int main() {
    int t,maxx=0,c=0;
    scanf("%d",&t);
    a[0] = 1e4;
    for(int i=1; i<=t; i++) {
        scanf("%d",a+i);
        if(a[i] > a[i-1]) maxx = max(++c,maxx);
        else c = 0;
    }
    printf("%d",maxx==0? maxx : maxx+1);
    return 0;
}

