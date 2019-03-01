#include <iostream>
#include <string.h>
#include <queue>
#include <string>
#include <cstdio>
#define LOCAL
using namespace std;
#define N 32

bool visite[N][N][N];
bool plat[N][N][N];

int X,Y,Floor;

struct  Node
{
    int x;
    int y;
    int floor;
    int step;
};

typedef Node NODE;

int dirx[6] = {1,-1,0,0,0,0};
int diry[6] = {0,0,1,-1,0,0};
int dirz[6] = {0,0,0,0,1,-1};

bool Equal(NODE a,NODE b)
{
    if(a.x==b.x && a.y==b.y && a.floor==b.floor) return true;
    else return false;
}

bool limite(NODE a)
{
    if(a.x < 0 || a.x >= X || a.y >= Y || a.y < 0 || a.floor<0 || a.floor >= Floor) return false;
    else return true;
}

int bfs(NODE x,NODE E)
{
    NODE now,next;
    queue<NODE> Link;
    Link.push(x);
    while(!Link.empty())
    {
        now = Link.front();
        Link.pop();
        for(int i=0; i<6; i++)
        {
            next.x = now.x+dirx[i];
            next.y = now.y+diry[i];
            next.floor = now.floor+dirz[i];
            next.step = now.step+1;
            if(Equal(E,next)) return next.step;
            if(limite(next) && plat[next.x][next.y][next.floor] && !visite[next.x][next.y][next.floor]) 
            {
                visite[next.x][next.y][next.floor]=1; 
                Link.push(next);
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
    char in;
    NODE st,ed;
    while(cin >> Floor >> X >> Y)
    {
        if(Floor==0 && X==0 && Y==0) break;
        memset(plat,0,sizeof(plat));
        memset(visite,0,sizeof(visite));
        for(int floor=0; floor<Floor; floor++)
        {
            for(int x=0; x<X; x++)
            {
                for(int y=0; y<Y; y++)
                {
                    cin >> in;
                    if(in == 'S')
                    {
                        st.x = x;
                        st.y = y;
                        st.floor = floor;
                        st.step = 0;
                        //WA-Reason
                        //visite[x][y][floor]=1;
                        //if Delete it , This Programmer Can be Accecept;
                    }
                    else if(in == 'E')
                    {
                        ed.x = x;
                        ed.y = y;
                        ed.floor = floor;
                    }
                    else if(in == '.')
                    {
                        plat[x][y][floor]=1;
                    }
                }
            }
        }
        int out = bfs(st,ed);
        if(out == -1) cout << "Trapped!";
        else printf("Escaped in %d minute(s).",out);
        cout << endl;
    }
    return 0;
}
