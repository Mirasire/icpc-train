#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

#define lc(x) x<<1
#define rc(x) x<<1|1
const int maxn = 1e3+100;

double sy[maxn<<1];
struct RECTANGEL {
	double x,y1,y2;
	int flag;
	void init(double a,double b1,double b2,int fl) { x=a; y1=b1; y2=b2; flag=fl; }
	bool operator < (const RECTANGEL& oth) { return x < oth.x; }
} rec[maxn<<3];
struct TREENODE {
	double l,r,sum,ts;
	int lazy;
	void init(double l1,double r1) { l=l1; r=r1; sum=0; lazy=0; }
} tn[maxn<<3];

void pushLazy(int idx) {
	TREENODE& now = tn[idx];
	// 1 or more
	if(now.lazy > 0) now.ts = now.r - now.l;
	else now.ts = tn[lc(idx)].ts + tn[rc(idx)].ts;
	//2 or more
	if(now.lazy > 1) now.sum = now.r - now.l;
	else if(now.lazy == 1) now.sum = tn[lc(idx)].ts + tn[rc(idx)].ts;
	else if(now.lazy == 0) now.sum = tn[lc(idx)].sum + tn[rc(idx)].sum;
}

void buildTree(int l,int r,int idx) {
	if(r-l > 1) {
		int mid = (l+r) >> 1;
		tn[idx].init(sy[l],sy[r]);
		buildTree(l,mid,lc(idx));
		buildTree(mid,r,rc(idx));
	} else {
		tn[idx].init(sy[l],sy[r]);
		tn[lc(idx)].init(0,0);
		tn[rc(idx)].init(0,0);
	}
}

void update(double tarL,double tarR, int idx,int add) {
	TREENODE& now = tn[idx];
	if(now.l == tarL && now.r == tarR) {
		now.lazy += add;
		pushLazy(idx);
		return;
	}
	TREENODE& ll = tn[lc(idx)];
	TREENODE& rr = tn[rc(idx)];
	if(ll.r > tarL) update(tarL,min(ll.r,tarR),lc(idx),add);
	if(rr.l < tarR) update(max(rr.l,tarL),tarR,rc(idx),add);
	pushLazy(idx);
}

int main() {
	int t,size,end,n;
	double x1,y1,x2,y2;
	double perX,ans;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		for(int i=0; i<n; i++) {
			scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
			rec[i].init(x1,y1,y2,1);
			rec[i+n].init(x2,y1,y2,-1);
			sy[i]=y1;
			sy[i+n]=y2;
		}

		end = n*2;
		sort(sy,sy+end);
		size = unique(sy,sy+end) - sy;
		buildTree(0,size-1,1);
		sort(rec,rec+end);

		ans = 0;
		perX = rec[0].x;
		double& len = tn[1].sum;
		for(int i=0; i<end; i++) {
			RECTANGEL& now = rec[i];
			ans += len*(now.x-perX);
			update(now.y1,now.y2,1,now.flag);
			perX = now.x;
		}
		printf("%.2lf\n",ans);
	}
	return 0;
}
