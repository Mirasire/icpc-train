#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> e[12];
int head[12];

int main() {
    int n,m,tmp1,tmp2;
    cin >> n >> m;

    int sum = 0;
    for(int i=1; i<=m; i++) {
        cin >> tmp1 >> tmp2;
        e[tmp1].push_back(tmp2);
		head[tmp2++];
		head[tmp2]++;
        e[tmp2].push_back(tmp1);
    }
    return 0;
}
