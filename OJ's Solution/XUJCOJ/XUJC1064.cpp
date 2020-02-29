#include <iostream>
#include <cstdio>
#include <queue>
#define LOCAL
using namespace std;

#define N 105
#define R 2

bool visite[N][N][R] = {0};
int plant[N][N];
int m,n;

typedef struct 
{
    int x;
    int y;
    int Rocket;
    int step;
}NODE;

bool Limite(NODE node)
{
    if(node.x < 0 || node.x>= m || node.y < 0 || node.y >= n || plant[node.x][node.y]==-1) return false;
    else return true;
}

int dirNormal[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int dirRoket[4][2] = {{0,2},{0,-2},{2,0},{-2,0}};

int bfs(NODE st,NODE E)
{
    NODE now,next;
    queue<NODE> ADT;
    ADT.push(st);
        // main BFS
        while(!ADT.empty())
        {
            now = ADT.front();
            ADT.pop();
            if(now.x==E.x && now.y==E.y) return now.step;
            if(now.Rocket)
            {
                for(int i=0; i<4; i++)
                {
                    next.x = now.x+dirRoket[i][0];
                    next.y = now.y+dirRoket[i][1];
                    if(Limite(next) && !visite[next.x][next.y][0]) 
                    {
                        visite[next.x][next.y][0] = 1;
                        next.step = now.step+1;
                        next.Rocket = 0;
                        ADT.push(next);
                    }
                }
            }
            for(int i=0; i<4; i++)
            {
                next.x = now.x+dirNormal[i][0];
                next.y = now.y+dirNormal[i][1];
                if(Limite(next) && !visite[next.x][next.y][now.Rocket]) 
                {
                    next.Rocket = now.Rocket;
                    visite[next.x][next.y][now.Rocket] = 1;
                    next.step = now.step+1;
                    ADT.push(next);
                }
            }
        }
    return -1;
}

int main()
{
#ifdef LOCAL
    freopen("in","r",stdin);
    freopen("out","w",stdout);
#endif
    cin >> m >> n;
    bool flag = 1;
    NODE st,ed;
    st.step=0;
    st.Rocket=1;
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
        {
            scanf("%d",&plant[i][j]);
            if(flag && plant[i][j]==0)
            {
                st.x = i;
                st.y = j;
                flag = 0;
                visite[i][j][0] = 1; //mark the roket is 0
                visite[i][j][1] = 1; //mark the roket is 1
            }
            else if(plant[i][j]==0)
            {
                ed.x = i;
                ed.y = j;
            }
        }
    printf("%d",bfs(st,ed));
    return 0;
}
