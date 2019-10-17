#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

const int  Hmaxn = 2e5+100;
vector<int> head[Hmaxn];
int ew[Hmaxn];

int main() {
    int n,m;
    int a,b;
    cin >> n >> m;
    for(int i=1; i<=n; i++) scanf("%d",ew+i);
    while(m--) {
        cin >> a >> b;
        head[a].push_back(b);
        head[b].push_back(a);
    }
    return 0;
}