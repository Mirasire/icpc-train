#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#define maxn 1010
using namespace std;
 
char s[maxn][maxn];
int g[maxn][maxn];
int T,n,m;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
 
bool inside(int cx,int cy)
{
    return cx>0 && cx<=n && cy>0 && cy<=m;
}
 
bool border(int cx,int cy)
{
    return cx==1 || cx==n || cy==1 || cy==m;
}
 
void init_fire()
{
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++) g[i][j]=99999999;
    queue<int> qx,qy;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            if (s[i][j]=='F') qx.push(i),qy.push(j),g[i][j]=0;
    while (!qx.empty())
    {
        int cx=qx.front(),cy=qy.front();
        qx.pop(),qy.pop();
        for (int i=0; i<4; i++)
        {
            if (!inside(cx+dx[i],cy+dy[i])) continue;
            if (s[cx+dx[i]][cy+dy[i]]!='.') continue;
            if (g[cx][cy]+1>=g[cx+dx[i]][cy+dy[i]]) continue;
            g[cx+dx[i]][cy+dy[i]]=g[cx][cy]+1;
            qx.push(cx+dx[i]),qy.push(cy+dy[i]);
        }
    }
}
 
int bfs()
{
    queue<int> qx,qy;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            if (s[i][j]=='J')
            {
                g[i][j]=0;
                qx.push(i),qy.push(j);
                if (border(i,j)) return 1;
            }
    while (!qx.empty())
    {
        int cx=qx.front(),cy=qy.front();
        qx.pop(),qy.pop();
        for (int i=0; i<4; i++)
        {
            if (s[cx+dx[i]][cy+dy[i]]!='.') continue;
            if (g[cx][cy]+1>=g[cx+dx[i]][cy+dy[i]]) continue;
            if (border(cx+dx[i],cy+dy[i])) return g[cx][cy]+2;
            g[cx+dx[i]][cy+dy[i]]=g[cx][cy]+1;
            qx.push(cx+dx[i]),qy.push(cy+dy[i]);
        }
    }
    return -1;
}
 
int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&n,&m);
        for (int i=1; i<=n; i++) scanf("%s",s[i]+1);
        init_fire();
        int ans=bfs();
        if (ans==-1) puts("IMPOSSIBLE");
            else printf("%d\n",ans);
 
    }
    return 0;
}