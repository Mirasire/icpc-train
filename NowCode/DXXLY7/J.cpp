#include <iostream>
#include <cstdio>
#include <cstdio>
using namespace std;

typedef long long ll;
ll res(ll x) {
    ll ans=0;
    while(x) {
        ans*=10;
        ans+=x%10;
        x/=10;
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    ll a,b;
    while(n--) {
        cin >> a >> b;
        cout << res(res(a)+res(b)) << endl;
    }
    return 0;
}
