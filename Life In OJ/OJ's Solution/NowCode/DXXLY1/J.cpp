#include <iostream>
#include <cstdio>
using namespace std;

typedef long long int ll;

int main() {
    ll x,a,y,b;
    while(cin >> x >> a >> y >> b) {
        ll r1 = x/a;
        ll r2 = y/b;
        x %= a;
        y %= b;
        if(r1 == r2) {
            if(x*b == y *a) cout << '=';
            else if(x*b > y *a) cout << '>';
            else cout << '<';
        }
        else if(r1 < r2) {
            cout << '<';
        } 
        else cout << '>';
        cout << endl;
    }
    return 0;
}

