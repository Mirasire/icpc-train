//Topological Sorting only useful for DAG
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int Hmaxn = 20;
vector<int> head[Hmaxn];
int in_edge[Hmaxn];
int n,m;

void topoSort() {
    int now,de;
    queue<int> L;
    vector<int> ans;
    for(int i=0; i < n; i++) {
        if(!in_edge[i]) L.push(i);
    }
    while(!L.empty()) {
        now = L.front();
        L.pop();
        ans.push_back(now);
        for(int i=0; i<head[now].size(); i++) {
            if(--in_edge[head[now][i]] == 0) L.push(head[now][i]);
        }
    }
    if(ans.size() == n)
        for(int i=0; i<ans.size(); i++) cout << ans[i] << " ";
    else 
        throw "error";
}

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