//AcVersion 0.01
#include <iostream>
#include <cstdio>
#include <queue>
#define LOCAL
using namespace std;

#define N 10
#define M 5

//data define 
int maze[N][N] = {0};
bool visite[N][N] = {0};
int dir[4][2] = {{ 0, 1}, { 0, -1}, { 1, 0}, { -1, 0}};

struct NODE
{
    int x;
    int y;
    struct NODE *before;
};

NODE tmp[100] = {0}; //for save ?

//function

void bfs(void);
void prtGraph(NODE *end);
bool limite(NODE toJude);

int main()
{
#ifdef LOCAL
    freopen("in","r",stdin);
    freopen("out","w",stdout);
#endif

    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            scanf("%d",&maze[i][j]);
        }
    }
    
    bfs();
    return 0;
}

bool limite(int x,int y)
{
    if( x<0 || x >= M || y<0 || y>=M || visite[x][y]) return false;
    else return true;
}

void prtGraph(NODE *end)
{
    if(end->before != NULL)
    {
        prtGraph(end->before);
        printf("(%d, %d)\n",end->x,end->y);
    }
    else
    {
        printf("(0, 0)\n");
        return;
    }
}

void bfs(void)
{
    int p = 0,r = 1;
    NODE now,next;
    now.x = 0;
    now.y = 0;
    now.before = NULL;
    tmp[0] = now;
    queue<NODE> ADT;
    ADT.push(now);
    while(!ADT.empty())
    {
        now = ADT.front();
        ADT.pop();
        next.before = &tmp[p];
        if(now.x == 4 && now.y == 4)
        {
            prtGraph(&now);
            break;
        }
        for(int i=0; i<4; i++)
        {
            next.x = now.x+dir[i][0];
            next.y = now.y+dir[i][1];
            if(limite(next.x,next.y) && !maze[next.x][next.y])
            {
                //for(int i=0; i<25; i++) cout << next.x << "  " << next.y << endl;
                visite[next.x][next.y] = 1;
                tmp[r++] = next;
                ADT.push(next);
            }
        }
        p++;
    }
    return;
}
