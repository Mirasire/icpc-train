#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn = 126000;
ll tmp[maxn];
ll arr[510];

bool cmp(int a,int b){
    return a>b;
}

int main(){
    int N,K;
    scanf("%d%d",&N,&K);
    for(int i=0; i<N; i++) scanf("%lld",arr+i);
    int index=0;
    for(int i=0; i<N; i++)
        for(int j=i+1; j<N; j++)
            tmp[index++] = arr[i] + arr[j];
    sort(tmp,tmp+index,cmp);
    ll out = 0;
    for(int i=0; i<K; i++) out+=tmp[i];
    printf("%lld",out);
    return 0;
}

