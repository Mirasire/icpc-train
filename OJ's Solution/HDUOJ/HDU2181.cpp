#include <cstdio>
#include <cstring>

const int maxn  = 25;
int city[maxn][3],prt[maxn],kase,st;
bool visite[maxn];

void dfs(int c,int len){
    visite[c] = 1;
    prt[len] = c;
    for(int i=0; i<3; i++){
        int next = city[c][i];
        if(len == 19 && next == st){
            printf("%d:  ",++kase);
            for(int i=0; i<20; i++) printf("%d ",prt[i]);
            printf("%d\n",st);
        }
        else if(!visite[next]) dfs(next,len+1);
    }
    visite[c] = 0;
    return;
}

int main(){
    for(int i=1; i<=20; i++) scanf("%d %d %d",&city[i][0],&city[i][1],&city[i][2]);
    while(scanf("%d",&st) != EOF){
        if(st==0) break;
        memset(prt,0,sizeof(prt));
        memset(visite,0,sizeof(visite));
        kase = 0;
        dfs(st,0);
    }
    return 0;
}


