#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long ll;

ll QuickFactor(ll a, ll b){
    ll re = 1;
    while(b){
        if(b&1) re*=a;
        b/=2;
        a*=a;
    }
    return re;
}

int main(){
    //freopen("in","r",stdin);
    ll n,x,cnt=0,add,basic;
    cin >> n;
    while(n--){
        cnt = 0;
        cin >> x;
        basic = x;
        while(basic%2==0) {
            cnt++;
            basic/=2;
        }
        add = QuickFactor(2,cnt) - 1;
        cout << x-add << " " << x+add << endl;
    }
    return 0;
}
