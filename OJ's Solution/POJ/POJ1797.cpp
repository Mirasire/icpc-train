//AC
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <string>
using namespace std;

const int Emaxn = 2e6+100,inf = 0x3f3f3f3f;
int head[Emaxn],d[Emaxn],cnt = 0,n;
bool vis[Emaxn];
struct EDGE{
	int to,next,w;
	void init(int to,int next,int w) {
		this->to = to;
		this->next = next;
		this->w = w;
	}
} e[Emaxn];

void AddEdge(int a,int b, int w) {
	e[++cnt].init(b,head[a],w); head[a] = cnt;
	e[++cnt].init(a,head[b],w); head[b] = cnt;
}

void init(int n) {
	cnt = 0;
	for(int i=0; i<=n; i++) {
		vis[i] = 0;
		head[i] = -1;
		d[i] = 0;
	}
}

void SPFA(int s) {
	int now;
	queue<int> list;
	list.push(s);
	d[s] = inf;
	vis[s] = 1;
	while(!list.empty()) {
		now = list.front();
		list.pop();
		vis[now] = 0;
		for(int i=head[now]; i!=-1; i=e[i].next) {
			EDGE& ee = e[i];
			if(min(ee.w,d[now]) > d[ee.to]) {
				d[ee.to] = min(ee.w,d[now]);
				if(!vis[ee.to]) {
					vis[ee.to] = 1;
					list.push(ee.to);
				}
			}
		}
	}
}

int main() {
	int t;
	int a,b,w,n,m;
	scanf("%d",&t);
	for(int i=1; i<=t; i++) {
		scanf("%d%d",&n,&m);
		init(n);
		while(m--) {
			scanf("%d%d%d",&a,&b,&w);
			AddEdge(a,b,w);
			AddEdge(b,a,w);
		}
		SPFA(1);
		printf("Scenario #%d:\n",i);
		printf("%d\n\n",d[n]);
	}
	return 0;
}
