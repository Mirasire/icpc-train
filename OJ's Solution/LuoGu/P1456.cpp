#include <bits/stdc++.h>
using namespace std;

#define ls(x) tn[x].l
#define rs(x) tn[x].r

const int maxn = 1e5+100;
struct NODE {
	int l,r,fa;
	int d,val;
} tn[maxn];

int find(int u) {
	int a=u,tp;
	while(tn[u].fa!=u) u=tn[u].fa;
	while(tn[a].fa!=u) { tp=tn[a].fa; tn[a].fa=u; a=tp; }
	return u;
}

int merge(int x,int y) {
	if(!x || !y) return x|y;
	if(tn[x].val < tn[y].val) swap(x,y);
	rs(x) = merge(rs(x),y);
	if(tn[ls(x)].d < tn[rs(x)].d) swap(ls(x),ls(y));
	//tn[x].fa = tn[ls(x)].fa = tn[rs(x)].fa = x;
	tn[x].d = tn[rs(x)].d+1;
	return x;
}
//void pop(int x) { tn[ls(x)].fa = tn[rs(x)].fa = tn[x].fa = merge(ls(x),ls(y)); }

int main() {
	std::ios::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	for(int i=1; i<=n; i++) tn[i].fa=i,cin >>tn[i].val;
	int x,y,fx,fy;
	while(m--) {
		cin >> x >> y;
		fx = find(x); fy = find(y);
		if(fx==fy) cout << -1 << endl;
		else {
			tn[x].l = tn[x].r = 0;
			tn[y].l = tn[y].r = 0;
			int tx = tn[ls(fx)].fa = tn[rs(fx)].fa = merge(ls(fx),rs(fx));
			int ty = tn[ls(fy)].fa = tn[rs(fy)].fa = merge(ls(fy),rs(fy));
			tn[fx].val>>=1; tn[fy].val>>=1;
			cout << max(tn[fx].val,tn[fy].val) << endl;
			tn[tx].fa = tn[fx].fa = merge(tx,fx);
			tn[ty].fa = tn[fy].fa = merge(ty,fy);
			//merge
		}
	}
	return 0;
}
