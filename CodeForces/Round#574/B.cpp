#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll maxn = 1e6;


ll sq(ll a) {
    for(ll i=0; i<maxn; i++) 
        if(i*i == a) return i;
}


int main(){
    ll n,k,sum;
    cin >> n >> k;
    cout << (ll)(n - ((-3+sq(9+8*(n+k)))/2));
    return 0;
}

