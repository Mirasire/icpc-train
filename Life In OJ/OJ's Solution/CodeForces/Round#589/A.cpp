#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
using namespace std;

int tmp;

bool slove(int a) {
    tmp = a;
    map<int,bool> app;
    while(a) {
        if(app[a%10]) return 0;
        app[a%10] = 1;
        a/=10;
    }
    printf("%d",tmp);
    return 1;
}

int main() {
    int a,b;
    cin >> a >> b;
    for(int i=a; i<=b; i++) {
        if(slove(i)) return 0;
    }
    printf("-1");
    return 0;
}
