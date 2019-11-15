#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <cstdio>
using namespace std;

#define lc(x) x<<1
#define rc(x) x<<1|1

const int maxn = 1e4+100;

int sgy[maxn<<1];
struct RECTANGEL {
	int x,y1,y2;
	int flag;
	void init(int a,int b1,int b2,int f1) { x=a; y1=b1; y2=b2; flag =f1;}
} rec[maxn<<3];

bool cmp(RECTANGEL a,RECTANGEL b) {
	return a.x < b.x;
}

struct TREENODE {
	int l,r,sum,nums,lazy;
	int lvis,rvis;
	//times 记录了这个区间被覆盖几次
	void init(int l1,int r1) { l=l1; r=r1; nums = lvis = rvis = lazy = sum = 0;}
} tn[maxn<<3];

void pushUP(int idx) {
	TREENODE& now = tn[idx];
	if(now.lazy > 0) now.sum = now.r - now.l;
	else now.sum = tn[lc(idx)].sum + tn[rc(idx)].sum;
}

void pushUPNum(int idx) {
	TREENODE& now = tn[idx];
	if(now.lazy > 0) now.lvis = now.rvis = now.nums = 1;
	else {
		now.lvis = tn[lc(idx)].lvis;
		now.rvis = tn[rc(idx)].rvis;
		now.nums = tn[lc(idx)].nums + tn[rc(idx)].nums - tn[lc(idx)].rvis*tn[rc(idx)].lvis;
	}
}

void buildTree(int l,int r,int idx) {
	if(r-l > 1) {
		int mid = (l+r)>>1;
		tn[idx].init(sgy[l],sgy[r]);
		buildTree(l,mid,lc(idx));
		buildTree(mid,r,rc(idx));
	} else {
		tn[idx].init(sgy[l],sgy[r]);
		tn[lc(idx)].init(0,0);
		tn[rc(idx)].init(0,0);
	}
	return;
}

void update(int tarL,int tarR,int idx,int add) {
	TREENODE& now = tn[idx];
	if(now.l == tarL && now.r == tarR) {
		now.lazy += add;
		pushUP(idx);
		pushUPNum(idx);
		return;
	}
	if(tn[lc(idx)].r > tarL) update(tarL,min(tarR,tn[lc(idx)].r),lc(idx),add);
	if(tn[rc(idx)].l < tarR) update(max(tarL,tn[rc(idx)].l),tarR,rc(idx),add);
	pushUP(idx);
	pushUPNum(idx);
}

int main() {
	int n,size,end,perLen,perX,perNum;
	int x1,x2,y1,y2,ans;
	while(~scanf("%d",&n)) {
		//init
		ans = 0;

		for(int i=0; i<n; i++) {
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			rec[i].init(x1,y1,y2,1);
			rec[i+n].init(x2,y1,y2,-1);
			sgy[i] = y1;
			sgy[i+n] = y2;
		}

		//lisan
		sort(sgy,sgy+2*n);
		size = unique(sgy,sgy+2*n) - sgy;

		//init
		buildTree(0,size-1,1);
		sort(rec,rec+2*n,cmp);

		end = 2*n;
		perLen = 0;
		perNum = 0;
		perX = rec[0].x;
		for(int i=0; i<end; i++) {
			RECTANGEL& now = rec[i];
			update(now.y1,now.y2,1,now.flag);
			ans += (int)abs(perLen - tn[1].sum) + 2*perNum*(now.x-perX);
			perLen = tn[1].sum;
			perNum = tn[1].nums;
			perX = now.x;
		}

		printf("%d\n",ans);
	}
	return 0;
}
