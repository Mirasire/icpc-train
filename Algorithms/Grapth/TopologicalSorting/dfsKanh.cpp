//Topological Sorting only useful for DAG
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int Hmaxn = 20;
vector<int> head[Hmaxn];
int in_edge[Hmaxn];
int n,m;

int main() {
    int a,b;
    cin >> n >> m;
    while(m--) {
        cin >> a >> b;
        head[a].push_back(b);
        in_edge[b]++;
    }
    topoSort();
    return 0;
}