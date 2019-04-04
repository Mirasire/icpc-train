#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 1e3 + 100;
bool fire[maxn][maxn], visite[maxn][maxn];
char maze[maxn][maxn];
int dir[4][2] = { { 0,1 },{ 0,-1 },{ 1,0 },{ -1,0 } };
struct Node
{
    int x, y;
    int step;
    Node() : step(0) {}
};
int R, C;
int endR, endC;
int task,task2; //fire's Spreaing wide
queue<Node> RUN, BURN;

bool Limite(int x, int y)
{
    if (x >= R || x<0 || y >= C || y<0) return 0;
    else if (maze[x][y] == 'F' || maze[x][y] == '#') return 0;
    return 1;
}

int bfs()
{
    Node now, next;
    while (!RUN.empty())
    {
        int tmp = task;
        task = 0;
        while (tmp--)
        {
            now = BURN.front();
            BURN.pop();
            for (int i = 0; i < 4; i++)
            {
                next.x = now.x + dir[i][0];
                next.y = now.y + dir[i][1];
                if (Limite(next.x, next.y) && fire[next.x][next.y] != 1)
                {
                    fire[next.x][next.y] = 1;
                    BURN.push(next);
                    task++;
                }
            }
        }
        tmp = task2;
        task2=0;
        while(tmp--)
        {
            now = RUN.front();
            RUN.pop();
            next.step = now.step + 1;
            if (now.x == 0 || now.x == endR || now.y == 0 || now.y == endC) return now.step;
            for (int i = 0; i<4; i++)
            {
                next.x = now.x + dir[i][0];
                next.y = now.y + dir[i][1];
                if (Limite(next.x, next.y) && fire[next.x][next.y] != 1 && visite[next.x][next.y] != 1)
                {
                    visite[next.x][next.y] = 1;
                    RUN.push(next);
                    task2++;
                }
            }
        }
    }
    return -1;   
}

int main()
{
    int n;
    scanf("%d", &n);
    Node tmp;
    while (n--)
    {
        while (!RUN.empty()) RUN.pop();
        while (!BURN.empty()) BURN.pop();
        memset(visite, 0, sizeof(visite));
        memset(fire, 0, sizeof(fire));
        scanf("%d%d", &R, &C);
        endC = C - 1, endR = R - 1;
        task = 0;
        for (int i = 0; i<R; i++)
            for (int j = 0; j<C; j++)
            {
                scanf(" %c", &maze[i][j]);
                if (maze[i][j] == 'F')
                {
                    tmp.x = i;
                    tmp.y = j;
                    BURN.push(tmp);
                    fire[i][j] = 1;
                    task++;
                }
                else if (maze[i][j] == 'J')
                {
                    tmp.x = i;
                    tmp.y = j;
                    RUN.push(tmp);
                    visite[i][j] = 1;
                }
            }
        task2=1;
        int out = bfs();
        if (out == -1) printf("IMPOSSIBLE\n");
        else printf("%d\n", out + 1);
    }
    return 0;
}
