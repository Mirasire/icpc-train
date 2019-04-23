#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,ans;
int dis[105][105];
bool vis[105][105];
void Reset()
{
    cin>>n>>m;
    ans=0;
    for (int  i=0;i<=n;i++)
        for (int j=0;j<=n;j++)
        {
            dis[i][j]=2147483647/2;
            vis[i][j]=false;
        }
    for (int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if (!vis[a][b])
        {
            vis[a][b]=true;
            vis[b][a]=true;
            dis[a][b]=c;
            dis[b][a]=c;
        }
        else
        {
  //          cout<<a<<' '<<b<<endl;
            ans++;
            dis[a][b]=min(dis[a][b],c);
            dis[b][a]=dis[a][b];
        }
    }
}
int main()
{
    int T;
    cin>>T;
    int cnt=0;
    while (T--)
    {
        //cout << "b " << ans << endl;
        Reset();
       // cout << "e " << ans << endl;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                for (int k=1;k<=n;k++)
                    if (dis[i][j]>=dis[i][k]+dis[k][j])
                    {
                        if (vis[i][j])
                        {
                            vis[i][j]=false;
                            vis[j][i]=false;
                         //   cout<<i<<' '<<j<<endl;
                            ans++;
                        }
                        dis[i][j]=dis[i][k]+dis[k][j];
                        dis[j][i]=dis[i][j];
                   }
        cnt++;
         printf("Case %d: %d\n",cnt,ans);
    }    
}
