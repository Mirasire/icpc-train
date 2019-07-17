#include <iostream>
#include <limits.h>
#include <queue>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

const int maxn = 15;
int tmp[maxn][maxn] = {0};
int maze[maxn][maxn];
int dir[4][2]  = {0,1,0,-1,1,0,-1,0};
int n,m;
int lon = INT_MIN;

bool limited(int x,int y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

void dfs(int step,int x,int y) {
    lon = max(step,lon);
    for(int  i=0; i<4; i++) {
        if(limited(x + dir[i][0], y + dir[i][1]) && maze[x+dir[i][0]][y+dir[i][1]] < maze[x][y]) {
                dfs(step + 1, x + dir[i][0], y + dir[i][1]);
            }
        }
    return;
}

int main() {
    freopen("in","r",stdin);
    cin >> n >> m;
    for(int i=0; i<n; i++) 
        for(int j=0; j<m; j++) 
            cin >> maze[i][j];

    for(int i=0; i<n; i++) 
        for(int j=0; j<m; j++) 
            dfs(1,i,j);

    cout << lon << endl;

    return 0;
}


