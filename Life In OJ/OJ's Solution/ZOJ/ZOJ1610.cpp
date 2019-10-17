#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 8e3+100;
int color[maxn << 2],width;
int idx[maxn],cnt[maxn];
int sec[maxn],ncol;

void down_color(int index) {
    if(color[index] != -1) {
        color[index<<1]  = color[index<<1|1] = color[index];
        color[index] = -1;
    }
}

void modify(int index,int L,int R,int l,int r,int def) {
    if(l >= L && r <= R) {
        color[index] = def;
        return;
    }
    int mid = (l+r)/2;
    down_color(index);
    if(mid >= L) modify(index<<1,L,R,l,mid,def);
    if(mid < R) modify(index<<1|1,L,R,mid+1,r,def);
}

void query(int index,int l,int r) {
    if(l == r) {
        if(color[index] >= 0 & color[index] != ncol) {
            //cout << color[index] << endl;
            cnt[color[index]]++;
            idx[width++] = color[index];
        }
        ncol = color[index];
    } else {
        down_color(index);
        int mid = (l+r)/2;
        query(index<<1,l,mid);
        query(index<<1|1,mid+1,r);
    } 
}

void Init(void) {
    memset(color,-1,sizeof(color));
    memset(cnt,0,sizeof(cnt));
    memset(idx,0,sizeof(idx));
}

int main() {
    //freopen("in","r",stdin);
    int i,j,n,beg,ed,def,size,ans_size;
    while(scanf("%d",&n) == 1) {
        Init();
        ncol = -1;
        width = 0;
        for(i=0; i<n; i++) {
            scanf("%d%d%d",&beg,&ed,&def);
            if(beg < ed) modify(1,beg+1,ed,1,8000,def);
        }
        //printf("modify ok\n");
        query(1,1,8000);
        //printf("query ok\n");
        sort(idx,idx+width);
        size = unique(idx,idx+width) - idx;
        //cout << "width " << width << endl;
        for(i=0; i<size; i++) {
            printf("%d %d\n",idx[i],cnt[idx[i]]);
        }
        printf("\n");
    }
    return 0;
}
