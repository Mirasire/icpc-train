//AC
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

const int Vmaxn = 2e3+100,Emaxn = 4e3+100,inf = 0x3f3f3f;
struct EDGE {
	int to,next,w;
	void def(int &to, int &next,int& w) {
		this-> to = to;
		this-> next = next;
		this-> w = w;
	}
};

struct SPFA {
	EDGE edge[Emaxn];
	int head[Vmaxn],d[Vmaxn],cnt;
	bool vis[Vmaxn];
	SPFA() {
		cnt = 0;
		memset(head,-1,sizeof(head));
		memset(vis,0,sizeof(vis));
	}
	void AddEdge(int a,int b,int w) {
		cnt++;
		edge[cnt].def(b,head[a],w);
		head[a] = cnt;
	}
	void runSpfa(int s,int n) {
		int now;
		for(int i=0; i<=n; i++) d[i] = inf;
		queue<int> list;
		list.push(s);
		vis[s] = 1;
		d[s] = 0;
		while(!list.empty()) {
			now = list.front();
			list.pop();
			vis[now] = 0;
			for(int i=head[now]; i!=-1; i=edge[i].next) {
				EDGE& e = edge[i];
				if(d[e.to] > d[now] + e.w) {
					d[e.to] = d[now] + e.w;
					if(!vis[e.to]) {
						vis[e.to] = 1;
						list.push(e.to);
					}
				}
			}
		}
	}
};

int main() {
	int n,m;
	int a,b,w;
	SPFA spfa;
	cin >> m >> n;
	while(m--) {
		cin >> a >> b >> w;
		spfa.AddEdge(a,b,w);
		spfa.AddEdge(b,a,w);
	}
	spfa.runSpfa(n,n);
	cout << spfa.d[1];
	return 0;
}
