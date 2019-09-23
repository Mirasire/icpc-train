#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

typedef long long ll;
const int Emaxn = 2e5+100,Hmaxn = 2e5+100;
struct  EDGE{
    int to,next,w;
} edge[Emaxn];
int head[Hmaxn],cnt,f[Hmaxn];
ll sumw;

void addEdge(int a,int b,int wb) {
    cnt++;
    edge[cnt].to = b;
    edge[cnt].w = wb;
    edge[cnt].next = head[a];
    head[a] = cnt;
}

void find(int &a) {
    int sa = a,tmp;
    while(f[a] != a) a = f[a];
    //Compress
    while(sa != a) {
        tmp = f[sa];
        f[sa] = a;
        sa = tmp;
    }
}

bool same(int a,int b) {return find(a) == find(b);}
void unite(int a,int b) {int fa = find(a), fb = find(b);f[fa] = fb;}