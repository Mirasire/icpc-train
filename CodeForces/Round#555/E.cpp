#include <set>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 2e5+500;
int arr[maxn];

int main(){
    freopen("in","r",stdin);
    int n,in;
    multiset<int> s;
    s.clear();
    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%d",arr+i);
    for(int i=0; i<n; i++){
        scanf("%d",&in);
        s.insert(in);
    }
    for(int i=0; i<n; i++){
        if(i) printf(" ");
        auto start = s.lower_bound((n-arr[i])%n);
        if(start == s.end()) start = s.begin();
        printf("%d",(arr[i] + *start)%n);
        s.erase(start);
    }
    printf("\n");
    return 0;
}
