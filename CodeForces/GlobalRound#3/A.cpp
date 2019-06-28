#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int main(){
    long long a,b,ab;
    cin >> a >> b >> ab;
    cout << min(a,b)*2 + (a!=b) + ab*2;
    return 0;
}
