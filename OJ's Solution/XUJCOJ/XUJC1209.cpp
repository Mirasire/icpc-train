#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
#include <limits.h>
using namespace std;

const int maxn = 1e4+5;
struct Node
{
    int a,c;
    int people;
    int Money;
    int index;
    Node (int a,int c):a(a),c(c),people(0),Money(0),index(-1) {}
    Node ():people(0),Money(0),index(-1) {}
};
bool visite[maxn];
Node Store[maxn];
int n,m,drive;
int Min;


bool cmp(Node ia,Node ib)
{
    if(ia.c==ib.c) return ia.a > ib.a;
    return ia.c < ib.c;
}

void bfs()
{
    Node now,next;
    queue<Node> Plan;
    Plan.push(now);
    while(!Plan.empty())
    {
        now = Plan.front();
        Plan.pop();
        if(n==now.people) 
        {
            Min = min(Min,now.Money);
            continue;
        }
        if(now.Money > Min) continue;
        for(int i=now.index+1; i<m; i++)
        {
            if((n-now.people) <= Store[i].a)
            {
                next.Money = now.Money+(n-now.people)*Store[i].c+drive;
                next.people = n;
            }
            else if((n-now.people) > Store[i].a)
            {
                next.Money = now.Money+Store[i].a*Store[i].c+drive;
                next.people = now.people+Store[i].a;
            }
            next.index = i;
            Plan.push(next);
            //printf("next->Money %d\nnext->people %d\n",next.Money,next.people);
        }
    }
}

int main()
{
    freopen("in","r",stdin);
    int T;
    cin >> T;
    while(T--)
    {
        Min = INT_MAX;
        scanf("%d%d",&n,&m);
        for(int i=0; i<m; i++) scanf("%d",&Store[i].a);
        for(int i=0; i<m; i++) scanf("%d",&Store[i].c);
        scanf("%d",&drive);
        sort(Store,Store+m,cmp);
        //for(int i=0; i<m; i++) printf("Node: %d %d\n",Store[i].a,Store[i].c);
        bfs();
        printf("%d\n",Min);
    }
    return 0;
}
