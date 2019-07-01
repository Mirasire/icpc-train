//Copy from https://www.cnblogs.com/yinbiao/p/9350894.html
#include<bits/stdc++.h>
using namespace std;
#define max_v 10
int G[max_v][max_v];
int dir[8][2]= {{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2}};
int step;
int sx,sy,fx,fy;
struct node
{
    int x,y,step;
};
void bfs()
{
    memset(G,0,sizeof(G));
    queue<node> q;
    node p,next;
    p.x=sx;
    p.y=sy;
    p.step=0;
    G[p.x][p.y]=1;
    q.push(p);

    while(!q.empty())
    {
        p=q.front();
        q.pop();

        if(p.x==fx&&p.y==fy)
        {
            step=p.step;
            return ;
        }

        for(int i=0; i<8; i++)
        {
            next.x=p.x+dir[i][0];
            next.y=p.y+dir[i][1];

            if(next.x>=1&&next.y>=1&&next.x<=8&&next.y<=8&&G[next.x][next.y]==0)
            {
                next.step=p.step+1;
                G[next.x][next.y]=1;
                q.push(next);
            }
        }
    }
}
int main()
{
    char c1,c2;
    int y1,y2;
    while(~scanf("%c%d %c%d",&c1,&y1,&c2,&y2))
    {
        getchar();
        sx=c1-'a'+1;
        sy=y1;
        fx=c2-'a'+1;
        fy=y2;
        bfs();
        printf("To get from %c%d to %c%d takes %d knight moves.\n",c1,y1,c2,y2,step);
    }
    return 0;
}
