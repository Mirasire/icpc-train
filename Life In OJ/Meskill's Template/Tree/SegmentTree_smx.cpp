//扫描线求重复覆盖面积
//HDU3642 扫描立方体
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

#define lc(x) x<<1
#define rc(x) x<<1|1
#define debug(x) printf(#x " = %d\n",x)

const int maxn = 1e3+100;
int sz[maxn<<2],sy[maxn<<2];
struct CUBE{
	int x,z1,z2,y1,y2;
	int flag;
	bool todo;
	void init(int x1,int a1,int a2,int b1,int b2,int fl) { x = x1; z1 = a1; z2 = a2; y1 = b1; y2 = b2; flag = fl; }
	bool operator < (CUBE& oth) { return x < oth.x; }
} cub[maxn<<3];

struct TREENODE {
	int l,r,lazy;
	int len1,len2,len3;
	void init(int l1,int r1) { l=l1; r=r1; lazy = len1 = len2 = len3 = 0; }
} tn[maxn<<3];

void pushUp(int idx) {
	TREENODE& now = tn[idx];
	//覆盖一次
	if(now.lazy >= 1) {
		now.len1 = now.r - now.l;
	} else {
		now.len1 = tn[lc(idx)].len1+tn[rc(idx)].len1;
	}

	//覆盖两次
	if(now.lazy >= 2) {
		now.len2 = now.r - now.l;
	} else if(now.lazy == 1){
		now.len2 = tn[lc(idx)].len1+tn[rc(idx)].len1;
	} else {
		now.len2 = tn[lc(idx)].len2+tn[rc(idx)].len2;
	}

	//覆盖三次
	if(now.lazy >= 3) {
		now.len3 = now.r - now.l;
	} else if(now.lazy == 1) {
		now.len3 = tn[lc(idx)].len2+tn[rc(idx)].len2;
	} else if(now.lazy == 2) {
		now.len3 = tn[lc(idx)].len1+tn[rc(idx)].len1;
	} else {
		now.len3 = tn[lc(idx)].len3+tn[rc(idx)].len3;
	}
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

void update(int tarL,int tarR,int idx,int add) {
	TREENODE& now = tn[idx];
	if(tarL == now.l && tarR == now.r) {
		now.lazy+=add;
		pushUp(idx);
		return;
	}
	TREENODE& ll = tn[lc(idx)];
	TREENODE& rr = tn[rc(idx)];
	if(ll.r > tarL) update(tarL,min(tarR,ll.r),lc(idx),add);
	if(rr.l < tarR) update(max(tarL,rr.l),tarR,rc(idx),add);
	pushUp(idx);
}

int main() {
	int t,n,sizeZ,sizeY,end;
	int kase =0;
	int x1,y1,z1,x2,y2,z2;
	long long int ans;
	scanf("%d",&t);
	while(t--) {
		//init
		ans = 0;

		scanf("%d",&n);
		for(int i=0; i<n; i++) {
			scanf("%d%d%d%d%d%d",&x1,&y1,&z1,&x2,&y2,&z2);
			cub[i].init(x1,z1,z2,y1,y2,1);
			cub[i+n].init(x2,z1,z2,y1,y2,-1);
			sz[i] = z1;
			sz[i+n] = z2;
		}
		
		//todo
		end = n<<1;
		sort(sz,sz+end);
		sort(cub,cub+end);
		sizeZ = unique(sz,sz+end) - sz;
		long long int perArea = 0;
		long long int perZ = sz[0];
 
		for(int i=0; i<sizeZ; i++) {
			int nowZ = sz[i];
			int cnt = 0;
			//readin
			for(int j=0; j<end; j++) {
				if(cub[j].z1 <= nowZ && cub[j].z2 > nowZ) {
					cub[j].todo = 1;
					sy[cnt++] = cub[j].y1;
					sy[cnt++] = cub[j].y2;
				} else {
					cub[j].todo = 0;
				}
			}

			//lisan
			sort(sy,sy+cnt);
			sizeY = unique(sy,sy+cnt) - sy;
			buildTree(0,sizeY-1,1);

			//calculate the volume
			ans += 1LL*perArea*(nowZ-perZ);

			//toCaculateArea
			int perX = 0;
			bool flag = 0;
			perArea = 0;
			for(int j=0; j<end; j++) {
				CUBE& now = cub[j];
				if(now.todo) {
					if(flag) perArea += 1LL*(now.x - perX)*tn[1].len3;
					else flag = 1;
					update(now.y1,now.y2,1,now.flag);
					perX = now.x;
				}
			}
			perZ = nowZ;
		}
		printf("Case %d: %lld\n",++kase,ans);
	}
	return 0;
}
