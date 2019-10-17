#include <cstdio>
#include <cstring>
#define LOCAL

const int maxn = 105;
char grid[maxn][maxn];
int x,y;

void dfs(int a,int b)
{
    if(a>=x || a<0 || b<0 || b>=y || grid[a][b]=='*') return;
    grid[a][b] = '*';
    for(int i=-1; i<=1; i++)
        for(int j=-1; j<=1; j++)
        {
            if(i!=0 || j!=0)    dfs(a+i,b+j);
        }
}


int main()
{
#ifdef LOCAL
    freopen("in","r",stdin);
    freopen("out","w",stdout);
#endif
    while(scanf("%d%d",&x,&y)==2 && x && y) 
    {
        int cnt=0;
        memset(grid,0,sizeof(grid));
        for(int i=0; i<x; i++) scanf("%s",grid[i]);
        for(int i=0; i<x; i++)
            for(int j=0; j<y; j++)
                if(grid[i][j]=='@') dfs(i,j),cnt++;
        printf("%d\n",cnt);
    }
    return 0;
}
