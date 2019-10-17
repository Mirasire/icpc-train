#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

const int maxn = 1e4+100;
int N,K,F;
struct NODE {
    int A,B;
} choise[maxn];

bool cmp(NODE a, NODE b) {
    return a.A  > b.A;
}

int main() {
    freopen("in","r",stdin);
    scanf("%d",&N);
    for(int i=0; i<N; i++) scanf("%d%d",&choise[i].A, &choise[i].B);
    choise[N].A = choise[N].B = 0;
    sort(choise,choise+N+1,cmp);
    scanf("%d%d", &K, &F);
    priority_queue<int> oil;
    int now = F,cnt = 0;
    for(int i=0; i<=N; i++) {
        while(now < K - choise[i].A) {
            if(oil.empty()) {
                printf("-1");
                return 0;
            }
            now += oil.top();
            oil.pop();
            cnt++;
        }
        oil.push(choise[i].B);
    }
    printf("%d",cnt);
    return 0;
}
        

