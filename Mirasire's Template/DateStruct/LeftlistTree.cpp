/* 
 * Autor: Mirasire 
 * GithubRepo: https://github.com/Mirasire/icpc-train/
 * Tag: leftlist Tree
 *
 */
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
	if(tn[ls(x)].d < tn[rs(x)].d) swap(ls(x),rs(x));
	//tn[x].fa = tn[ls(x)].fa = tn[rs(x)].fa = x;
	tn[x].d = tn[rs(x)].d+1;
	return x;
}
//void pop(int x) { tn[ls(x)].fa = tn[rs(x)].fa = tn[x].fa = merge(ls(x),ls(y)); }
