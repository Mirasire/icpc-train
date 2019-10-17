#include <stdio.h>
#include <string>
#include <cstdio>
#include <iostream>
using namespace std;
string up;
int n,m;

int find(char target,int size){
    size--;
    int step=0;
    for(int i=0; i<size; i++){
        if(up[i] == target){
            step++;
            if(up[i+1] == target) return step;
        }
    }
    return step;
}

void solve(){
    int lon = up.size();
    if(up[0]=='U' && up[lon-1]=='R'){
        for(int i=0; i<m; i++) printf("R");
        for(int i=0; i<n; i++) printf("U");
    }
    else if(up[0]=='R' && up[lon-1]=='U'){
        for(int i=0; i<n; i++) printf("U");
        for(int i=0; i<m; i++) printf("R");
    }
    else if(up[0] == 'U' && up[lon-1] == 'U'){
        int middle = find('R',lon);
        if(middle != m){
            for(int i=0; i<middle; i++) printf("R");
            for(int i=0; i<n; i++) printf("U");
            for(int i=middle; i<m; i++) printf("R");
        }
        else printf("impossible");
    }
    else if(up[0] == 'R' && up[lon-1] == 'R'){
        int middle = find('U',lon);
        if(middle != n){
            for(int i=0; i<middle; i++) printf("U");
            for(int i=0; i<m; i++) printf("R");
            for(int i=middle; i<n; i++) printf("U");
        }
        else printf("impossible");
    }
    printf("\n");
    return;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        cin >> up;
        solve();
    }
    return 0;
}
