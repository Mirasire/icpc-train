//ambiguous: 貌似是重定义问题，只要换个名字就OK了
//Aleardy Ac
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int start,ed;
const int maxn = 1e6;
int Prime[maxn] = {0};
bool isNotPrime[maxn] = {0};
bool visite[maxn] = {0};

struct Node
{
    int Digital[4];
    int step;
    Node() : step(0) {}
    Node(int *in): step(0)
    {
        for(int i=0; i<4; i++) Digital[i] = in[i];
    }
    int getNumber() 
    {
        return Digital[0]+Digital[1]*10+Digital[2]*100+Digital[3]*1000;
    }
};

int bfs(Node start)
{
    Node now,next;
    now = start;
    queue<Node> path;
    path.push(now);
    while(!path.empty())
    {
        now = path.front();
        path.pop();
        if(now.getNumber()==ed) return now.step;
        for(int i=0; i<4; i++)
        {
            next = now;
            next.step = now.step+1;
            for(int index=0; index<10; index++)
            {
                next.Digital[i] = index;
                int key = next.getNumber();
                if(key > 1000 && key < 10000 && !isNotPrime[key] && !visite[key])
                {
                    visite[key] = 1;
                    path.push(next);
                }
            }
        }
    }
    return 0;
}

int main()
{
    //Euler Prime
    int index = 0;
    isNotPrime[0] = isNotPrime[1] = 1;
    for(int i=0; i<maxn; i++)
    {
        if(!isNotPrime[i]) Prime[index++] = i;
        for(int j=0; j<index&&i*Prime[j]<maxn; j++)
        {
            isNotPrime[i*Prime[j]] = 1;
            if(!(i%Prime[j])) break;
        }
    }
    int n;
    scanf("%d",&n);
    while(n--)
    {
        memset(visite,0,sizeof(visite));
        scanf("%d%d",&start,&ed);
        visite[start] = 1;
        int digital[4] = {0};
        int cnt=0;
        while(start)
        {
            digital[cnt++] = start%10;
            start/=10;
        }
        //for(int i=0; i<4; i++) printf("%d: %d\n",i,digital[i]);
        Node fresh(digital);
        //for(int i=0; i<4; i++) printf("%d: %d\n",i,fresh.Digital[i]);
        printf("%d\n",bfs(fresh));
    }
    return 0;
}
