#include <iostream>
#include <cstring>
#include  <cstdio>
#include <string>
#include <algorithm>
using namespace std;
 
const int maxn = 1e3+100;
int arr[maxn];
 
int main() {
    int k,n,now,ans;
    scanf("%d",&k);
    while(k--) {
        ans = 0;
        scanf("%d",&n);
        for(int i=0; i<n; i++) scanf("%d",arr+i);
        sort(arr,arr+n);
        for(int i=n-1; i>=0; i--) {
            ans++;
            arr[i];
            if(arr[i] >= ans) now = 0;
            else ans--,break;
        }
        printf("%d\n",ans);
    }
    return 0;
}