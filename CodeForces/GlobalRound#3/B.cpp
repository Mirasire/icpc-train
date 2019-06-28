#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
    long long n,m,ta,tb,k;
    cin >> n >> m >> ta >> tb >> k;
    if(k >= min(n,m)){
        cout << -1;
        return 0;
    }
    vector<long long> a,b;
    for(long long i=0; i<n; i++) {
        long long in;
        cin >> in;
        in += ta;
        a.push_back(in);
    }
    for(long long i=0; i<m; i++) {
        long long in;
        cin >> in;
        b.push_back(in);
    }
    long long ans = 0;
    for(long long i=0; i<min(k+1,n); i++){
        long long idx = lower_bound(b.begin(),b.end(),a[i]) - b.begin() + k - i;
        if(idx >= m){ //0 - m-1
            cout << -1;
            return 0;
        }
        ans = max(ans,b[idx] + tb);
    }
    cout << ans;
    return 0;
}

