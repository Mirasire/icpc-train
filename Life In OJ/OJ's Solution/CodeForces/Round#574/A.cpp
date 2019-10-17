#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1e3+100;
int people[maxn],cups;

bool cmp(int a,int b) {
    return a>b;
}

int main() {
    int n,k,index;
    freopen("in","r",stdin);
    scanf("%d%d",&n,&k);
    cups = n/2 + (n%2!=0);
    for(int i=0; i<n; i++) {
        scanf("%d",&index);
        people[index]++;
    }
    int cnt = 0;
    sort(people,people+1001,cmp);
    for(int i=0; i<maxn && cups; i++) {
        if(people[i]/2 > 0) {
            cnt += (people[i]/2) * 2;
            cups -= people[i]/2;
            people[i] = people[i]%2;
        }
    }
    for(int i=0; i<maxn&&cups; i++) {
        cnt++;
        cups--;
        people[i] =  0;
    }
    printf("%d",cnt);
    return 0;
}


