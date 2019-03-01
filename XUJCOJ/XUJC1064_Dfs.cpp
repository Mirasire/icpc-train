#include <iostream>
#include <limits.h>
#define LOCAL
using namespace std;

int m,n;
int MIN = INT_MAX;
int stx,sty,edx,edy;

#define N 105
bool visite[N][N] = {0};
int plant[N][N];

int NormalStep[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};
int RocketStep[4][2] = {{0,2},{0,-2},{-2,0},{2,0}};

void dfs(int x,int y,int roket,int cnt)
{
    if(x<0 || x>= m || y < 0 || y >= n || plant[x][y]==-1) return;
    if(x==edx && y == edy)  MIN = min(MIN,cnt);

    //well run circle
    if(roket)
    {
        for(int i=0; i<4; i++)
        {
            
            dfs(x+RocketStep[i][0],y+RocketStep[i][1],0,cnt++);
            dfs(x+NormalStep[i][0],y+NormalStep[i][1],1,cnt++);
        }
    }
    else
    {
        for(int i=0; i<4; i++)
        {
            dfs(x+NormalStep[i][0],y+NormalStep[i][1],0,cnt++);
        }
    }
    return;
}

int main()
{
#ifdef LOCAL
    freopen("in","r",stdin);
    freopen("out","w",stdout);
#endif
    scanf("%d%d",&m,&n);
    bool flag=1;
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
        {
            scanf("%d",&plant[i][j]);
            if(flag&&plant[i][j]==0)
            {
                stx = i;
                sty = j;
                flag = 0;
                visite[i][j]=1;
            }
            else if(plant[i][j])
            {
                edx = i;
                edy = j;
            }
        }
    dfs(stx,sty,1,0);
    printf("%d",MIN == INT_MAX ? -1 : MIN);
    return 0;
}
