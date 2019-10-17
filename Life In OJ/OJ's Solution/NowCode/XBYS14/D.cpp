#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    int arr[n+10];
    for(int i=0; i<n; i++) scanf("%d",arr+i);
    sort(arr,arr+n);
    printf("%d\n",arr[k-1]);
    return 0;
}
