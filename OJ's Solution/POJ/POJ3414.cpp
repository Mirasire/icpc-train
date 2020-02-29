#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <string>
using namespace std;

#define Prt(x) printf(#x "= %d\n",x) 
struct Node
{
    int i,j;
    int step;
};

struct PrtNode
{
    int FrontX,FrontY;
    int Handle;  //0-5
    PrtNode() : FrontX(-1),FrontY(-1) {}
    void Insert(Node a,int handle)
    {
        FrontX = a.i;
        FrontY = a.j;
        Handle = handle;
    }
};


const int maxn = 2e2;
const string Out[6] = {"FILL(1)","FILL(2)","DROP(1)","DROP(2)","POUR(1,2)","POUR(2,1)"}; 
int A,B,C;
int DIF;
bool visite[maxn][maxn];
PrtNode PrtList[maxn][maxn];

void PrintHandle(int x)
{
    cout << Out[x] << endl;
}

void PrintLink(PrtNode Now)
{
    if(Now.FrontY == -1 && Now.FrontX == -1 ) return;
    PrintLink(PrtList[Now.FrontX][Now.FrontY]);
    PrintHandle(Now.Handle);
    return;
}

void Add(Node now,Node next,int handle)
{
    visite[next.i][next.j] = 1;
    PrtList[next.i][next.j].Insert(now,handle);
}

int bfs()
{
    int handle;
    Node now,next;
    queue<Node> List;
    now.i = 0;
    now.j = 0;
    now.step = 0;
    List.push(now);
    while(!List.empty())
    {
        now = List.front();
        List.pop();
        //Print
        if(now.i == C || now.j == C) 
        {
            printf("%d\n",now.step);
            PrintLink(PrtList[now.i][now.j]);
            return 0;
        }
        //FILL i
        handle = 0;
        if(now.i < A) 
        {
            next = now;
            next.step = now.step+1;
            next.i = A;
            if(!visite[next.i][next.j]) 
            {
                Add(now,next,handle);
                List.push(next);
            }
        }
        //FILL j
        handle = 1;
        if(now.j < B) 
        {
            next = now;
            next.step = now.step+1;
            next.j = B;
            if(!visite[next.i][next.j]) 
            {
                Add(now,next,handle);
                List.push(next);
            }
        }
        //DROP i
        handle = 2;
        if(now.i > 0) 
        {
            next = now;
            next.step = now.step+1;
            next.i = 0;
            if(!visite[next.i][next.j]) 
            {
                Add(now,next,handle);
                List.push(next);
            }
        }
        //DROP j
        handle = 3;
        if(now.j > 0) 
        {
            next = now;
            next.step = now.step+1;
            next.j = 0;
            if(!visite[next.i][next.j]) 
            {
                Add(now,next,handle);
                List.push(next);
            }
        }
        //POUR(i,j)
        DIF = B - now.j; 
        handle = 4;
        if(now.i <= DIF)
        {
            next = now;
            next.step = now.step+1;
            next.i = 0;
            next.j += now.i;
            if(!visite[next.i][next.j]) 
            {
                Add(now,next,handle);
                List.push(next);
            }
        }
        if(now.i > DIF)
        {
            next = now;
            next.step = now.step+1;
            next.i -= DIF;
            next.j = B;
            if(!visite[next.i][next.j]) 
            {
                Add(now,next,handle);
                List.push(next);
            }
        }
        //POUR(j,i)
        DIF = A - now.i; 
        handle = 5;
        if(now.j <= DIF)
        {
            next = now;
            next.step = now.step+1;
            next.j = 0;
            next.i += now.j;
            if(!visite[next.i][next.j]) 
            {
                Add(now,next,handle);
                List.push(next);
            }
        }
        if(now.j > DIF)
        {
            next = now;
            next.step = now.step+1;
            next.j -= DIF;
            next.i = A;
            if(!visite[next.i][next.j]) 
            {
                Add(now,next,handle);
                List.push(next);
            }
        }
    }
    return 1;
}


int main()
{
    PrtList[0][0].FrontX = -1;
    PrtList[0][0].FrontY = -1;
    visite[0][0] = 1;
    scanf("%d%d%d",&A,&B,&C);
    int jude = bfs();
    if(jude) printf("impossible\n");
    return 0;
}
