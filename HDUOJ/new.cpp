#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <vector>
using namespace std;
 
const int maxn=5e5+10;
int hh[9]={1,1,2,6,24,120,720,5040,40320};
struct node{
    int num;
    char ch;
}pre[maxn];
int vis[maxn];
int vis2[maxn];
struct node2{
    string c;
    int num;
}e;
int dir[4]={-3,3,-1,1};
char a[30],d[10]={"udlr"},d2[10]={"durl"};
string b="123456780";
void show(int x)
{
    if(pre[x].num==-1)return ;
    show(pre[x].num);
    printf("%c",pre[x].ch);
}
int get_hh(string e)//获得hash值，康托展开
{
    int s=0,i,j,k;
    for(i=0;i<9;i++)
    {
        k=0;
        for(j=0;j<i;j++)
            if(e[j]>e[i])k++;
        s+=k*hh[i];
    }
    return s;
}
void bfs()
{
    vis[get_hh(e.c)]=1;
    pre[1].num=-1;
    int num=2,x,i,j,k,p,q;
    node2 f,g;
    f.c=b;
    f.num=8;
    pre[2].num=-1;
    vis2[get_hh(f.c)]=2;
    queue<node2>q1;
    queue<node2>q2;
    q1.push(e);
    q2.push(f);
    while(!q1.empty()&&!q2.empty())
    {
        f=q1.front();
        q1.pop();
        p=get_hh(f.c);
        if(vis2[p])
        {
            show(vis[p]);
            k=vis2[p];
            while(pre[k].num!=-1)
            {
                printf("%c",pre[k].ch);
                k=pre[k].num;
            }
            printf("\n");
            return ;
        }
        for(i=0;i<4;i++)
        {
            if(i==0&&f.num<3)continue;
            if(i==1&&f.num>5)continue;
            if(i==2&&f.num%3==0)continue;
            if(i==3&&f.num%3==2)continue;
            x=f.num+dir[i];
            g=f;
            swap(g.c[f.num],g.c[x]);
            q=get_hh(g.c);
            if(vis[q])continue;
            vis[q]=++num;
            g.num=x;
            pre[num].num=vis[p];
            pre[num].ch=d[i];
            q1.push(g);
        }
 
        f=q2.front();
        q2.pop();
        p=get_hh(f.c);
        if(vis[p])
        {
            show(vis[p]);
            k=vis2[p];
            while(pre[k].num!=-1)
            {
                printf("%c",pre[k].ch);
                k=pre[k].num;
            }
            printf("\n");
            return ;
        }
        for(i=0;i<4;i++)
        {
            if(i==0&&f.num<3)continue;
            if(i==1&&f.num>5)continue;
            if(i==2&&f.num%3==0)continue;
            if(i==3&&f.num%3==2)continue;
            x=f.num+dir[i];
            g=f;
            swap(g.c[f.num],g.c[x]);
            q=get_hh(g.c);
            if(vis2[q])continue;
            vis2[q]=++num;
            g.num=x;
            pre[num].num=vis2[p];
            pre[num].ch=d2[i];
            q2.push(g);
        }
    }
    printf("unsolvable\n");
}
int main()
{
    freopen("in","r",stdin);
    while(gets(a))
    {
        int i,j,k=0,n;
        n=strlen(a);
        e.c="";
        for(i=0,j=0;i<n;i++)
            if(a[i]!=' ')
            {
                if(a[i]=='x'){e.num=j;e.c+='0';}
                else e.c+=a[i];
                j++;
            }
        for(i=0;i<9;i++)
        {
            //printf("%c\n",e.c[i]);
            if(e.c[i]=='0')continue;
            for(j=0;j<i;j++)
            {
                if(e.c[j]=='0')continue;
                if(e.c[j]>e.c[i])k++;
            }
        }
        memset(vis2,0,sizeof(vis2));
        memset(vis,0,sizeof(vis));
        if(k&1)printf("unsolvable\n");
        else bfs();
    }
    return 0;
}
