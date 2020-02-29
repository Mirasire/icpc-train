#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int maxn = 2e4+100,INF = 0x3f3f3f3f;

struct Edge {
	int to,nxt,val;
	void init(int a,int b,int c) {
		to = a;
		nxt = b;
		val = c;
	}
} edge[maxn];
int head[maxn],cnt,n,m,dist[maxn];

void addEdge(int a,int b,int w) {
	cnt++;
	edge[cnt].init(b,head[a],w); head[a] = cnt;
}

bool bellman_frod() {
	//Bellman_Ford
	for(int i=0; i<n; i++) {
		bool flag = 0;
		for(int j=1; j<=n; j++) {
			for(int k= head[j]; k!=-1; k=edge[k].nxt) {
				Edge& e = edge[k];
				if(e.val + dist[j] < dist[e.to]) {
					dist[e.to] =  e.val + dist[j],flag=1;
					cnt++;
					if(cnt >= n ) return 0; //Bellman_Frod 最多进行 n-1 次松弛操作
				}
			}
		}
		if(!flag) break;
	}
	return 1;
}

int main() {
	int type,a,b,diff;
	cnt = -1;
	scanf("%d%d",&n,&m);
	memset(head,-1,sizeof(head));
	for(int i=0; i<=maxn; i++) dist[i] = INF;
	while(m--) {
		scanf("%d%d%d",&type,&a,&b);
		if(type==3) {
			addEdge(a,b,0);
			addEdge(b,a,0);
		} else {
			scanf("%d",&diff);
			if(type==1) {
				addEdge(a,b,-diff);
			} else {
				addEdge(b,a,diff);
			}
		}
	}
	dist[1] = 0;
	cnt = 0;
	if(bellman_frod()) printf("Yes\n");
	else printf("No\n");
	return 0;
}
