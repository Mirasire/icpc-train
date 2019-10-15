#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
using namespace std;

const int Hmax = 60,Pmax = 13;

struct EDGE {
	int to,next,flow,cap;
	EDGE(int to,int next,int flow,int cap):to(to),next(next),flow(flow),cap(cap) {}
	void init(int to,int next,int flow,int cap) {
		this->to = to;
		this->next = next;
		this->flow = flow;
		this->cap = cap;
	}
} edge[Hmax<<1];
int cnt = -1;
int head[Hmax<<1];

void addEdge(int a,int b,int cap) {
	edge[++cnt].init(b,head[a],0,cap); head[a]=cnt;
	edge[++cnt].init(a,head[b],0,0); head[b]=cnt;
}

int main() {
	return 0;
}
