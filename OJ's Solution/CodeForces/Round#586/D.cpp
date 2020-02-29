//Learn From kaike's Blog
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 2e5 + 100;
typedef long long ll;
ll num[maxn];
vector<int> a[80];

int main() {
    int n,k;
    ll x;
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        scanf("%lld",num+i);
        k = 0;
        x = num[i];
        while(x%2==0) {
            k++;
            x>>=1;
        }
		//cout << k << endl;
        a[k].push_back(i);
    }
    int m = -1;
    for(int i=0; i<=64; i++) 
        if(m==-1 || a[i].size() > a[m].size()) m = i;
    printf("%lu\n",n - a[k].size());
    for(int i=0; i<=64; i++) {
        if(i==m) continue;
        for(int j=0; j<a[i].size(); j++)
            printf("%lld ",num[a[i][j]]);
    }
}
