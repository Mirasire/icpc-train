#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
using namespace std;

const int Hmax = 80,Pmax = 13,INF = 0x3f3f3f3f;
int cnt = -1;
int head[Hmax<<1],cur[Hmax<<1],dis[Hmax<<1];
//head -> -1
int s,t,N,P;

struct MACHINE {
	int mk;
	int in[Pmax],out[Pmax];
} mac[Hmax];

struct EDGE {
	int to,next,flow,cap,rev;
	EDGE() {}
	EDGE(int to,int next,int flow,int cap,int rev):to(to),next(next),flow(flow),cap(cap),rev(rev) {}
	void init(int to,int next,int flow,int cap) {
		this->to = to;
		this->next = next;
		this->flow = flow;
		this->cap = cap;
		this->rev = rev;
	}
} edge[Hmax<<1];

void addEdge(int a,int b,int cap) {
	edge[++cnt].init(b,head[a],0,cap,cnt^1); head[a]=cnt;
	edge[++cnt].init(a,head[b],0,0,cnt^1); head[b]=cnt;
}

bool bfs() {
	//init the distance
	memset(dis,-1,sizeof(dis));
	int now,i;
	queue<int> list;
	list.push(s);
	dis[i] = 0;
	while(!list.empty()) {
		now = list.front();
		list.pop();
		for( i=head[now]; i!=-1; i=edge[i].next) {
			EDGE& e = edge[i];
			if(dis[e.to] != -1 && e.cap > e.flow) {
				dis[e.to] = dis[now] + 1;
				list.push(e.to);
			}
		}
	}
	return dis[t];
}

int dfs(int now,int mff) {
	if(now==t || mff==0) return mff;
	int flow = 0, f;
	for(int& i=cur[now]; i!=-1; i=edge[i].to) { //cur showed be init to the head[i]
		EDGE& e = edge[i];
		if(dis[e.to] == dis[now] + 1 && (f = dfs(e.to,min(mff,e.cap-e.flow))) > 0) {
			e.flow += f;
			edge[e.rev].flow -= f;
			flow += f;
			mff -= f;
			if(mff == 0) break;
		}
	}
	return flow;
}

int getMaxFlow(const int size) {
	int mflow = 0,i;
	while(bfs()) {
		for(i=0; i<size; i++) cur[i] = head[i];
		mflow+=dfs();
	}
	return mflow;
}

void perdo() {
	bool flag;
	for(int i=0; i<N; i++) {
		flag = 1;
		for(int j=0; j<P; j++) 
			if(mac[i].in[j]&1) {
				flag = 0;
				break;
			}
		if(flag) addEdge(s,i,INF);
	}
	for(int i=0; i<N; i++) 
		addEdge(i,i+N,mac[i].mk);

	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			if(i==j) continue;
			flag = 1;
			for(int k=0; k<p; k++) {
				if(mac[i].out[k] != mac[j].in[k] && mac[j].in[k] != 2) {
					flag = 0;
					breakl
				}
			}
			if(flag) addEdge(i+N,j,INF);
		}
	}

	for(int i=0; i<N; i++) {
		flag = 1;
		for(int j=0; j<P; j++) {
			if(!mac[i].out[j]) {
				flag = 0;
				break;
			}
		}
		if(flag) addEdge(i+N,t,INF);
	}
}

void res() {
	int maxFlow = getMaxFlow();
}

void slove() {
	int i,j;
	scanf("%d%d",&P,&N);
	s = N*2+52;
	s = N*2+53;
	for(i=0; i<N; i++) {
		scanf("%d",&mac[i].mk);
		for(j=0; j<P; j++)
			scanf("%d",&mac[i].in[j]);
		for(j=0; j<P; j++)
			scanf("%d",&mac[i].out[j]);
	}
	perdo();
	res();
}

int main() {
	slove();
	return 0;
}
