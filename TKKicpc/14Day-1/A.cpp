#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;
#define LOCAL

const int N=10;

bool plat[N][N];
bool visit[N];
int n,k;
long long int path;

void dfs(int x,int number)
{
    if(number == k)
    {
        path++;
        return;
    }
    if(x >= n) return;
    for(int j=0; j<n; j++)
    {
        if(plat[x][j] && !visit[j])
        {
            visit[j] = 1;
            dfs(x+1,number+1);
            visit[j] = 0;
        }
    }
    dfs(x+1,number);
    return;
}

int main()
{
#ifdef LOCAL
    freopen("in","r",stdin);
    freopen("out","w",stdout);
#endif
    while(cin >> n >> k)
    {
        string in;
        if(n==-1&&k==-1) break;
        for(int i=0; i<n; i++)
        {
            cin >> in;
            for(int j=0; j<n; j++)
            {
                if(in[j] == '#') plat[i][j]=1;
                else plat[i][j]=0;
            }
        }
        path=0;
        memset(visit,0,sizeof(visit));
        dfs(0,0);
        printf("%lld\n",path);
    }
    return 0;
}
