#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;

const int maxn = 1e9;
bool noPrime[maxn];
int Prime[maxn/10];

int main() {
    noPrime[0] = noPrime[1] = 1;
    int cnt = 0;
    for(int i=0; i<maxn; i++) {
        if(!noPrime[i]) Prime[cnt++] = i;
        for(int j=0; j<cnt && i*Prime[j]<maxn; j++) {
            noPrime[i*Prime[j]] = 1;
            if(!(i%Prime[j])) break;
        }
    }
    cout << Prime[cnt-1] << endl;
    return 0;
}
