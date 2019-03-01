#include <iostream>
#include <cstdio>
#include <queue>
#define LOCAL
using namespace std;

int m,n;  //cin plat's weight && lenth

//Struct define 
struct node
{
    int x;
    int y;
    int step;
    bool Rocket;
};

typedef node NODE;

#define N 105 

int plat[N][N];
bool visite[N][N] = {0};
bool Rvisite[N][N] = {0};

// walk define 
int NormalStep[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int RocketStep[4][2] = {{0,2},{0,-2},{2,0},{-2,0}};

bool limite(int x,int y)
{
    if( x < 0 || x >= m || y < 0 || y >= n || plat[x][y] == -1 ) return false;
    else return true;
}

int bfs(NODE x,NODE ED)
{
    NODE now,next;
    queue<NODE> ADT;
    ADT.push(x);
    while(!ADT.empty())
    {
        now = ADT.front();
        ADT.pop();
        if(now.x == ED.x && now.y == ED.y) return now.step;
        for(int i=0; i<4; i++)
        {
            next.x = now.x + NormalStep[i][0];
            next.y = now.y + NormalStep[i][1];
            next.Rocket = now.Rocket;
            next.step = now.step+1;
            if(limite(next.x,next.y) && !visite[next.x][next.y])
            {
                if(next.Rocket) visite[next.x][next.y]=1;
                ADT.push(next);
            }
        }
        for(int i=0; i<4&&now.Rocket; i++)
        {
            next.x = now.x + RocketStep[i][0];
            next.y = now.y + RocketStep[i][1];
            next.Rocket=0;
            next.step=now.step+1;
            if(limite(next.x,next.y) && !Rvisite[next.x][next.y] && !visite[next.x][next.y])
            {
                Rvisite[next.x][next.y]=1;
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
    scanf("%d%d",&m,&n);
    NODE st,ed;
    st.Rocket = 1;
    st.step = 0;
    ed  = st;
    bool flag=1;
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
        {
            scanf("%d",&plat[i][j]);
            if(flag && plat[i][j]==0)
            {
                st.x = i;
                st.y = j;
                flag = 0;
                visite[i][j]=1;
            }
            else if(plat[i][j] == 0)
            {
                ed.x = i;
                ed.y = j;
            }
        }
    printf("%d",bfs(st,ed));
    return 0;
}

        


        


        


        


