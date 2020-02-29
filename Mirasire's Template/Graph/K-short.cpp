//K短路-模板
//介绍: 有向图，自身的1短路不是0
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;

#define debug(x) printf(#x " = %d\n",x);

//const num
const int Hmaxn = 1e3+100,Emaxn = 1e5+100,INF = 0x3f3f3f;

//memory
struct Eddge {
	int to,nxt,w;
	void def(int a,int b,int wi) { to = a; nxt = b; w = wi; }
};
int head[Hmaxn],revhead[Hmaxn],H[Hmaxn];
int fcnt,rcnt;
bool vis[Hmaxn];
Eddge fedge[Emaxn],redge[Emaxn];

void FaddEdge(int u,int v,int wi) { fedge[++fcnt].def(v,head[u],wi); head[u] = fcnt; }
void RaddEdge(int u,int v,int wi) { redge[++rcnt].def(v,revhead[u],wi); revhead[u] = rcnt; }

struct RESTA {
	int u,f;
	RESTA() {}
	RESTA(int u,int f):u(u),f(f) {}
	bool operator < (const RESTA& oth) const { return oth.f < f; }
};
struct STA {
	int u,f;
	STA() {}
	STA(int u,int f):u(u),f(f) {}
	bool operator < (const STA& oth) const { return oth.f + H[oth.u] < f + H[u]; }
};
priority_queue<RESTA> rlist;
priority_queue<STA> flist;

int main() {
	//Init
	fcnt = rcnt = 0;
	int n,m;
	int s,t,k;
	int u,v,we;
	while(~scanf("%d%d",&n,&m)) {
		for(int i=0; i<=n; i++) { H[i]=INF; head[i] = revhead[i] = -1; vis[i] = 0;}
		for(int i=0; i<m; i++) {
			scanf("%d%d%d",&u,&v,&we);
			FaddEdge(u,v,we);
			RaddEdge(v,u,we);
		}
		scanf("%d%d%d",&s,&t,&k);
		if(s==t) k++; //!!!! s = t的第一短路经不是直接走自身

		//find h(x) as H(x)
		RESTA now;
		rlist.push({t,0});
		H[t] = 0;
		while(!rlist.empty()) {
			now = rlist.top();
			rlist.pop();
			if(vis[now.u]) continue;
			vis[now.u] = 1;
			for(int i=revhead[now.u]; i!=-1; i=redge[i].nxt) {
				if(H[redge[i].to] > now.f + redge[i].w) {
					H[redge[i].to] = now.f + redge[i].w;
					rlist.push({redge[i].to,H[redge[i].to]});
				}
			}
		}

		//find k-short A*
		STA now2;
		flist.push({s,0});
		while(!flist.empty()) {
			now2 = flist.top();
			flist.pop();
			if(now2.u == t) {
				//debug(now2.f);
				k--;
				if(k==0) {
					printf("%d",now2.f);
					break;
				}
			}
			for(int i=head[now2.u]; i!=-1; i=fedge[i].nxt) {
				flist.push({fedge[i].to,now2.f+fedge[i].w});
			}
		}
		if(k) printf("-1\n");
	}
	return 0;
}
