#include <cstdio>
#include <limits.h>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long li;

int maxn = 1e4+10;
ll MAX = LONG_MAX;
li arr[maxn];
bool isPrime[MAX];
li Prime[MAX];

int main(){
    set<li> s;
    int n,k,i,index=0,key,cnt=0;
    isPrime[0] = isPrime[1] = 1;
    for(int i=0; i<MAX; i++){
        if(!isPrime[i]) Prime[cnt++] = i;
        for(int j=0; j<cnt && Prime[j]*i < MAX; j++){
            isPrime[Prime[j]*i] = 1;
            if(!(i%Prime[j])) break;
        }
    }
    scanf("%d%d",&n,&k);
    for(i=0,index=0; i<n; i++){
        scanf("%d",&key);
        if(!s.count(key)){
            s.insert(key);
            arr[index++] = key;
        }
    }
    sort(arr,arr+index);
    li m = arr[n-k] - arr[k-1];
    if(isPrime[m] == 0){
        printf("YES\n%d\n",m);
    }
    else {
        printf("NO\n");
    }
    return 0;
}
