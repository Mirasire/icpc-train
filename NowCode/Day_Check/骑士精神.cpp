#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <cmath>
#include <cstdio>
using namespace std;
const int D = 1;
const int D2 = sqrt(5);
const int maxn = 10;
int maze[10][5];
bool flag;
int target[10][5] = {
    {1,1,1,1,1},
    {0,1,1,1,1},
    {0,0,2,1,1},
    {0,0,0,0,1},
    {0,0,0,0,0},
};
 
string tmp;
 
int dir[8][2] = {{2,1},{2,-1},{1,2},{1,-2},{-2,1},{-2,-1},{-1,2},{-1,-2}};
int deep; //记录限制深度
int check(){
    int cnt=0;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(maze[i][j] != 2 && target[i][j] != maze[i][j]){
                cnt++;
            }
        }
    }
    return cnt;
}

int get_h(int x,int y){
    int dx = abs(x-2),dy = abs(y-2);
    return D*(dx+dy) + (D2-D)*min(dx,dy);
}


void dfs(int x,int y,int now){
    if(now > deep || !flag) return;
    if(check() == 0){
        flag = 0;
        return;
    }
    for(int i=0; i<8; i++){
        int next_x = x + dir[i][0];
        int next_y = y + dir[i][1];
        if(next_x < 0 || next_y < 0 || next_x >= 5 || next_y >= 5) continue;
        if(check() + now > deep) continue;
        swap(maze[x][y] , maze[next_x][next_y]);
        dfs(next_x,next_y,now+1);
        swap(maze[x][y] , maze[next_x][next_y]);
    }
    return;
}
 
int main(){
    freopen("in","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        int x,y;
        for(int i=0; i<5; i++){
            cin >> tmp;
            for(int j=0; j<5; j++){
                if(tmp[j] !='*') maze[i][j] = tmp[j] - '0';
                else maze[i][j] = 2,x = i, y = j;
            }
        }
        flag = 1;
        for(deep=0; deep<16&&flag; deep++){
            dfs(x,y,0); 
            if(!flag) printf("%d\n",deep);
        }
        if(flag) printf("-1\n");
    }
    return 0;
}
