#include <bits/stdc++.h>
using namespace std;

#define ls(x) tn[x].l
#define rs(x) tn[x].r
const int maxn=1e6+5;
struct NODE {
	int l,r,fa;
	int val,d;
} tn[maxn];

int merge(int x,int y) {
	if(!x||!y) return x|y;
	if(tn[x].val > tn[y].val) swap(x,y);
	rs(x) = merge(rs(x),y);
	if(tn[ls(x)].d < tn[rs(x)].d) swap(ls(x),rs(x));
	tn[x].d = tn[rs(x)].d+1;
	return x;
}

void pop(int x) {
	tn[x].val = -1;
	tn[ls(x)].fa = tn[rs(x)].fa = tn[x].fa = merge(ls(x),rs(x));
}

int find(int u) {
	int a=u,tp;
	while(tn[u].fa!=u) u=tn[u].fa;
	while(tn[a].fa!=u) { tp=tn[a].fa; tn[a].fa=u; a=tp; }
	return u;
}

int main() {
	std::ios::sync_with_stdio(false);
	tn[0].d=-1;
	int n,m,x,y,fx,fy;
	char op;
	cin >> n;
	for(int i=1; i<=n; i++) tn[i].fa=i,cin >> tn[i].val;
	cin >> m;
	while(m--) {
		cin >> op >> x;
		if(op=='M') {
			cin >> y;
			if(tn[x].val == -1 || tn[y].val==-1) continue;
			else {
				fx = find(x); fy = find(y);
				//IMPORTANT
				if(fx!=fy) tn[fx].fa = tn[fy].fa = merge(fx,fy);
			}
		} else {
			if(tn[x].val == -1) cout << 0 << endl;
			else {
				fx = find(x);
				cout << tn[fx].val << endl;
				pop(fx);
			}
		}
	}
	return 0;
}
