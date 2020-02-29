#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;

struct NODE{
    int value;
    int index;
};
const int maxn = 1e5+100;
int u[maxn],v[maxn];

bool operator < (const NODE &A,const NODE &B) {
    return A.value < B.value;
}

int main() {
    int n;
    while(scanf("%d",&n)!=EOF) {
        for(int i=0; i<n; i++)  scanf("%d",u+i);
        for(int i=0; i<n; i++)  scanf("%d",v+i);
        int p = 0;
        NODE now;
        for(int j=0; j<n; j++) {
            priority_queue<NODE> list1,list2;
            for(int i=j; i<maxn; i++) {
                now.index = i+1;
                now.value = u[i];
                list1.push(now);
                now.value = v[i];
                list2.push(now);
                if(list1.top().index == list2.top().index) p = list1.top().index;
            }
        }
        printf("%d\n",p);
    }
    return 0;
}

