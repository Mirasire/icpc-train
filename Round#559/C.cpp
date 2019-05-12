#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <limits.h>
using namespace std;

const int maxn = 1e5+100;
int b[maxn],g[maxn];

void cmp(int a,int b){
    return a > b;
}

int main(){
    int n,m;
    int x=0,y=0;
    long long out = 0;
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++){
        int key = 0;
        scanf("%d",&key);
        if(key) b[x++] = key;
    }
    for(int i=0; i<m; i++){
        int key = 0;
        scanf("%d",&key);
        if(key) g[y++] = key;
    }
    sort(b,b+x,cmp);
    sort(g,g+y);
    if(b[0] > g[n-1]) printf("-1\n");
    else{
        for(int i=
