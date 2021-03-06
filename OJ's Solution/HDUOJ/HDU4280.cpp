//AC
//毒瘤题卡Dinic
//KuangbinSAP模板题目
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAXN=100010;//点数的最大值
const int MAXM=400010;//边数的最大值
const int INF=0x3f3f3f3f;
struct Node{
    int from,to,next;
    int cap;
}edge[MAXM];

int tol,n;//n是总的点的个数，包括源点和汇点
int head[MAXN];
int dep[MAXN];
int gap[MAXN];//gap[x]=y :说明残留网络中dep[i]==x的个数为y

void init(){
    tol=0;
    memset(head,-1,sizeof(head));
}
void add_edge(int u,int v,int w){
    edge[tol].from=u;edge[tol].to=v;
    edge[tol].cap=w;edge[tol].next=head[u];
    head[u]=tol++;
    edge[tol].from=v;edge[tol].to=u;
    edge[tol].cap=0;edge[tol].next=head[v];
    head[v]=tol++;
}
void BFS(int start,int end){
    memset(dep,-1,sizeof(dep));
    memset(gap,0,sizeof(gap));
    gap[0]=1;
    int que[MAXN];
    int front=0,rear=0;
    dep[end]=0;
    que[rear++]=end;
    while(front!=rear){
        int u=que[front++];
        if(front==MAXN)front=0;
        for(int i=head[u];i!=-1;i=edge[i].next){
            int v=edge[i].to;
            if(dep[v]!=-1)continue;
            que[rear++]=v;
            if(rear==MAXN)rear=0;
            dep[v]=dep[u]+1;
            ++gap[dep[v]];
        }
    }
}
int SAP(int start,int end){
    int res=0;
    BFS(start,end);
    int cur[MAXN],S[MAXN];
    int top=0;
    memcpy(cur,head,sizeof(head));
    int u=start;
    int i;
    while(dep[start]<n){
        if(u==end){
            int temp=INF;
            int inser;
            for(i=0;i<top;i++)
               if(temp>edge[S[i]].cap){
                   temp=edge[S[i]].cap;
                   inser=i;
               }
            for(i=0;i<top;i++){
                edge[S[i]].cap-=temp;
                edge[S[i]^1].cap+=temp;
            }
            res+=temp;
            top=inser;
            u=edge[S[top]].from;
        }
        if(u!=end&&gap[dep[u]-1]==0)//出现断层，无增广路
          break;
        for(i=cur[u];i!=-1;i=edge[i].next)
           if(edge[i].cap!=0&&dep[u]==dep[edge[i].to]+1)
             break;
        if(i!=-1){
            cur[u]=i;
            S[top++]=i;
            u=edge[i].to;
        }else{
            int min=n;
            for(i=head[u];i!=-1;i=edge[i].next){
                if(edge[i].cap==0)continue;
                if(min>dep[edge[i].to]){
                    min=dep[edge[i].to];
                    cur[u]=i;
                }
            }
            --gap[dep[u]];
            dep[u]=min+1;
            ++gap[dep[u]];
            if(u!=start)u=edge[S[--top]].from;
        }
    }
    return res;
}

int main() {
	int T,m,s,t;
	int ex,wx,x,y;
	int a,b,c;
	scanf("%d",&T);
	while(T--) {
		ex = INF;
		wx = -INF;
		scanf("%d%d",&n,&m);
		init();
		for(int i=1; i<=n; i++) {
			scanf("%d%d",&x,&y);
			if(x < ex) s = i,ex = x;
			if(x > wx) t = i,wx = x;
		}
		for(int i=0; i<m; i++) {
			scanf("%d%d%d",&a,&b,&c);
			add_edge(a,b,c);
			add_edge(b,a,c);
		}
		printf("%d\n",SAP(s,t));
	}
	return 0;
}
