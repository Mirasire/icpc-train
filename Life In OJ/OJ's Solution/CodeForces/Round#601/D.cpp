//直接🐍型走位构造即可
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;

const int maxn = 120;
int rices,mk,bt,tp;
string str  = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
char fr[maxn][maxn];
char out[maxn][maxn];
bool vis[maxn][maxn];
int r,c,k;
int getIdx(int num) {
    if(num <= (mk*(bt+1))) return (num-1)/(bt+1);
    num -= mk*(bt+1);
    return (mk + (num-1)/bt);
}

int main() {
    int t,num;
    int nn,idx;
    scanf("%d",&t);
    while(t--) {
        idx = nn = num = 0;
        memset(vis,0,sizeof(vis));
        scanf("%d%d%d",&r,&c,&k);
        for(int i=0; i<r; i++) {
            scanf(" %s",fr[i]);
            for(int j=0; j<c; j++) {
                if(fr[i][j] == 'R') num++;
            }
        }
        bt = num/k; mk = num%k;
        for(int i=0; i<r; i++) {
            if(i%2==0) {
                for(int j=0; j<c; j++) {
                    if(fr[i][j]=='R') {
                        nn++;
                        idx = getIdx(nn);
                    }
                    out[i][j] = str[idx];
                }
            } else {
                for(int j=c-1; j>=0; j--) {
                    if(fr[i][j]=='R') {
                        nn++;
                        idx = getIdx(nn);
                    }
                    out[i][j] = str[idx];
                }
            }
        }
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) putchar(out[i][j]);
            putchar('\n');
        }
    }
    return 0;
}