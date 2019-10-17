#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1e5+100;
int maze[2][maxn];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0; i<2; i++)
        for(int j=0; j<n; j++){
            scanf("%d",maze[i]+j);
        }
    int cnt = 0;
    int s=0,d=0;
    for(int i=0; i<n; i++){
        if(maze[1][i] || maze[0][i]){
                s = i;
                break;
        }
    }
    for(int i=n-1; i>=0; i--){
        if(maze[1][i] || maze[0][i]){
                d = i;
                break;
        }
    }
    for(int i=s; i<d; i++){
        if(maze[1][i] && maze[0][i]){
            if(!maze[1][i+1] && !maze[0][i+1]){
                cnt++;
                maze[1][i+1]=1;
                maze[0][i+1]=1;
            }
        }
        else if(maze[1][i] && !maze[0][i]){
            if(!maze[1][i+1]){
                cnt++;
                maze[1][i+1]=1;
            }
        }
        else if(!maze[1][i] && maze[0][i]){
            if(!maze[0][i+1]){
                cnt++;
                maze[0][i+1]=1;
            }
        }
    }
    printf("%d",cnt);
    return 0;
}
