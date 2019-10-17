#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[10];

int main() {
    cin >> a[0];
    cin >> a[1];
    cin >> a[2];
    cin >> a[3];
    sort(a,a+4);
    if(a[0]+a[3] == a[1] + a[2]) cout << "YES";
    else if(a[3] == a[0] + a[1] + a[2])  cout << "YES";
    else cout << "NO";
    return 0;
}
