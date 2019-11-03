#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

const int Vmaxn = 1e4+100,Emaxn = 5e5+100,inf = 2147483647;
struct EDGE{
	int to,next,w;
} edge[Emaxn];

int head[Vmaxn],d[Vmaxn],cnt = 0;
int n,m;
bool vis[Vmaxn];

void init() {
	memset(head,-1,sizeof(head));
	memset(vis,0,sizeof(vis));
}

void AddEdge(int a,int b,int w) {
	edge[++cnt].to = b;
	edge[cnt].next = head[a];
	edge[cnt].w = w;
	head[a] = cnt;
}

void spfa(int s) {
	int now;
	for(int i=0; i<=n; i++) d[i] = inf; //Re_Reason: n is error to m
	queue<int> list;
	list.push(s);
	vis[s] = 1;
	d[s] = 0;
	while(!list.empty()) {
		now = list.front();
		list.pop();
		vis[now] = 0;
		for(int i=head[now]; i!=-1; i=edge[i].next) {
			EDGE &e = edge[i];
			if(d[e.to] > d[now] + e.w) {
				d[e.to]  = d[now] + e.w;
				if(!vis[e.to]) {
					vis[e.to] = 1;
					list.push(e.to);
				}
			}
		}
	}
}

int main() {
	init();
	int a,b,w,s;
	cin >> n >> m >> s;
	for(int i=0; i<m; i++) {
		cin >> a >> b >> w;
		AddEdge(a,b,w);
	}
	spfa(s);
	for(int i=1; i<=n; i++) cout << d[i] << " " ;
	return 0;
}
