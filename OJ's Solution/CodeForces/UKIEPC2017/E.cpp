#include <iostream>
#include <limits.h>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 5e3+100;

struct TY {
    int p,v;
    int num;
    bool vis;
    TY():vis(0) {}
};
struct ND{
    int bb,num;
};
TY box[maxn];
ND mm[maxn];
int ans[maxn];

bool cmp(TY a,TY b) {
    if(a.p==b.p) return a.v < b.v;
    return a.p < b.p;
};

bool cmp1(ND a,ND b) {
    return a.bb > b.bb;
};

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++){
        scanf("%d",&mm[i].bb);
        mm[i].num = i;
    }
    for(int i=0; i<m; i++) scanf("%d",&box[i].v);
    for(int i=0; i<m; i++) {
        scanf("%d",&box[i].p);
        box[i].num = i+1;
    }
    sort(mm,mm+n,cmp1);
    sort(box,box+m,cmp);
    int j=0,flag=1;
    for(int i=0; i<n&&flag; i++) {
        j=0;
        while(flag) {
            //cout << box[j].v << " " << box[j].p << endl;
            if(box[j].v >= mm[i].bb && !box[j].vis) {
                ans[mm[i].num] = box[j].num;
                box[j].vis = 1;
                break;
            }
            j++;
            if(j==m) flag=0;
        }
    }
    if(flag) {
        for(int i=0; i<n; i++) printf("%d ",ans[i]);
    } else 
        printf("impossible");
    return 0;
}
        
