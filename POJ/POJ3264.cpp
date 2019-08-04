#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;

const int maxn = 2e5+10;
struct TY {
    int minn,maxx;
    TY(): maxx(INT_MIN),minn(INT_MAX) {};
};
TY cow[maxn << 2];

void up(int index) {
    cow[index].minn = min(cow[index<<2].minn,cow[index<<2|1]minn);
    cow[index].maxx = max(cow[index<<2].maxx,cow[index<<2|1]maxx);
}



