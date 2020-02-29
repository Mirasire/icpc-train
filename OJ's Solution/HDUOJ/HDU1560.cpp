#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

string str[10];
int pos[10];
int n,deep,ans;
bool flag;
string op = "ACGT";

void dfs(int now_step){
    int old[10];
    if(!flag) return;
    if(now_step > deep) return;
    int Max = 0;
    for(int i=0; i<n; i++){
        Max = max((int)(str[i].size() - pos[i]),Max);
    }
    if(Max == 0){
        flag = 0;
        return;
    }
    if(now_step+Max > deep) return;
    for(int i=0; i<4; i++){
        memcpy(old,pos,sizeof(int)*10);
        bool flag = 0;
        for(int j=0; j<n; j++){
            if(str[j][pos[j]] == op[i]){
                pos[j]++;
                flag = 1;
            }
        }
        if(flag){
            dfs(now_step+1);
            memcpy(pos,old,sizeof(int)*10);
        }
    }
    return;
}


int main(){
    freopen("in","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=0; i<n; i++) cin >> str[i];
        flag = 1;
        deep = ans = 0;
        while(flag){
            memset(pos,0,sizeof(int)*10);
            dfs(0);
            if(!flag) printf("%d\n",deep);
            deep++;
        }
    }
    return 0;
}

