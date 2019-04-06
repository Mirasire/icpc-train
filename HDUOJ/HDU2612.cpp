#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <cstdio>
#include <queue>
#include <string>
using namespace std;

struct Node
{
    int x,y,times;
    Node() :x(0),y(0),times(0) {}
    Node(int x,int y,int times) :x(x),y(y),times(times) {}
};

const int maxn = 210;
bool visite[maxn][maxn];
int Y[maxn][maxn];
int Min = INT_MAX;
int dir[4][2] = {0,1,0,-1,1,0,-1,0};
int n,m;
char maze[maxn][maxn];

void Bfs(Node st,bool sit)
{
    memset(visite,0,sizeof(visite));
    Node now,next;
    queue<Node> KFC;
    KFC.push(st);
    visite[st.x][st.y] = 1;
    while(!KFC.empty())
    {
        now = KFC.front();
        KFC.pop();
        if(sit && maze[now.x][now.y]=='@') Min = min(Min,now.times+Y[now.x][now.y]);
        next.times = now.times+11;
        for(int i=0; i<4; i++)
        {
            next.x = now.x + dir[i][0];
            next.y = now.y + dir[i][1];
            if(next.x >= 0 && next.x < n && next.y >=0 && next.y < m && maze[next.x][next.y] != '#' && (!visite[next.x][next.y]))
            {
                visite[next.x][next.y] = 1;
                if(!sit && maze[next.x][next.y]=='@') Y[next.x][next.y] = next.times;
                KFC.push(next);
            }
        }
    }
    return;
}

int main()
{
    //freopen("in","r",stdin);
    while(scanf("%d%d",&n,&m) != EOF)
    {
        Node Ys,Ms;
        string in;
        memset(Y,0,sizeof(Y));
        for(int i=0; i<n; i++)
        {
            cin >> in;
            for(int j=0; j<m; j++)
            {
                maze[i][j] = in[j];
                if(maze[i][j] == 'Y')
                {
                    Ys.x = i;
                    Ys.y = j;
                }
                else if(maze[i][j] == 'M')
                {
                    Ms.x = i;
                    Ms.y = j;
                }
            }
        }
        Min = INT_MAX;
        Bfs(Ys,0);
        Bfs(Ms,1);
        printf("%d\n",Min);
    }
}
