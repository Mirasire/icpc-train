#define LOCAL
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;


const int maxn = 100+5;
bool vis[maxn][maxn][maxn];
int S,N,M;
struct Node
{
    int step;
    int s,n,m;
    Node ():step(0),s(0),n(0),m(0) {}
    Node (int x):step(0),s(x),n(0),m(0) {}
};
typedef struct Node Bowl;

int bfs()
{
    if(M*2 < S && N*2 < S) return -1;
    memset(vis,0,sizeof(vis));
    Bowl st(S),now,next;
    queue<Bowl> Link;
    Link.push(st);
    while(!Link.empty())
    {
        now = Link.front();
        Link.pop();
        if(2*now.s == S || 2*now.n == S || 2*now.m == S)
            return now.step + (now.s&&now.n&&now.m != 0);
        //s->m
        next = now;
        next.step=now.step+1;
        if(now.s+now.m < M)
        {
            next.s=0,next.m = now.m+now.s;
            if(!vis[next.s][next.n][next.m])
            {
                vis[next.s][next.n][next.m] = 1;
                Link.push(next);
            }
        }
        else
        {
            next.s=now.s-(M-next.m),next.m = M;
            if(!vis[next.s][next.n][next.m])
            {
                vis[next.s][next.n][next.m] = 1;
                Link.push(next);
            }
        }
        //s->n
        next = now;
        next.step=now.step+1;
        if(now.s+now.n < N)
        {
            next.s=0,next.n = now.n+now.s;
            if(!vis[next.s][next.n][next.m])
            {
                vis[next.s][next.n][next.m] = 1;
                Link.push(next);
            }
        }
        else
        {
            next.s=now.s-(N-next.n),next.n = N;
            if(!vis[next.s][next.n][next.m])
            {
                vis[next.s][next.n][next.m] = 1;
                Link.push(next);
            }
        }
        //m->s
        next = now;
        next.step=now.step+1;
        if(now.s+now.m < S)
        {
            next.m=0,next.s = now.m+now.s;
            if(!vis[next.s][next.n][next.m])
            {
                vis[next.s][next.n][next.m] = 1;
                Link.push(next);
            }
        }
        else
        {
            next.m=now.m-(S-next.s),next.s = S;
            if(!vis[next.s][next.n][next.m])
            {
                vis[next.s][next.n][next.m] = 1;
                Link.push(next);
            }
        }
        //n->s
        next = now;
        next.step=now.step+1;
        if(now.s+now.n < S)
        {
            next.n=0,next.s = now.n+now.s;
            if(!vis[next.s][next.n][next.m])
            {
                vis[next.s][next.n][next.m] = 1;
                Link.push(next);
            }
        }
        else
        {
            next.n=now.n-(S-next.s),next.s = S;
            if(!vis[next.s][next.n][next.m])
            {
                vis[next.s][next.n][next.m] = 1;
                Link.push(next);
            }
        }
        //m->n
        next = now;
        next.step=now.step+1;
        if(now.n+now.m < N)
        {
            next.m=0,next.n = now.m+now.n;
            if(!vis[next.s][next.n][next.m])
            {
                vis[next.s][next.n][next.m] = 1;
                Link.push(next);
            }
        }
        else
        {
            next.m=now.m-(N-next.n),next.n = N;
            if(!vis[next.s][next.n][next.m])
            {
                vis[next.s][next.n][next.m] = 1;
                Link.push(next);
            }
        }
        //n->m
        next = now;
        next.step=now.step+1;
        if(now.n+now.m < M)
        {
            next.n=0,next.m = now.m+now.n;
            if(!vis[next.s][next.n][next.m])
            {
                vis[next.s][next.n][next.m] = 1;
                Link.push(next);
            }
        }
        else
        {
            next.n=now.n-(M-next.m),next.m = M; //WA because you write M as S what a stupid wrong
            if(!vis[next.s][next.n][next.m])
            {
                vis[next.s][next.n][next.m] = 1;
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
#endif
    while(scanf("%d%d%d",&S,&N,&M))
    {
        if(N==0&&M==0&&S==0) break;
        int out = bfs();
        if(S&1 || out==-1) printf("NO\n");
        else printf("%d\n",out);
    }
    return 0;
}
