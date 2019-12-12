//替罪羊树 LuoGu P3369
#include <bits/stdc++.h>
using namespace std;

#define debug(x) printf(#x " = %d\n",x);

const int maxn = 1e5+100;
const double alpha = 0.75;
struct NODE {
	int l,r,val;
	int size,fact;
	bool exits;
} tzy[maxn];
int root,cnt;

void newNode(int& now,int val) {
	now = ++cnt;
	tzy[now].l = tzy[now].r = 0;
	tzy[now].val = val;
	tzy[now].exits = 1;
	tzy[now].size = tzy[now].fact = 1;
}

bool imbalance(int now) {
	if(max(tzy[tzy[now].l].size,tzy[tzy[now].r].size) > tzy[now].size*alpha 
		|| (tzy[now].size - tzy[now].fact) > 0.3*tzy[now].size)
		return 1;
	return 0;
}

vector<int> v;
void ldr(int now) {
	if(!now) return;
	ldr(tzy[now].l);
	if(tzy[now].exits) v.push_back(now);
	ldr(tzy[now].r);
}

void lift(int l,int r, int& now) {
	if(l==r) {
		now = v[l];
		tzy[now].l = tzy[now].r = 0;
		tzy[now].size = tzy[now].fact = 1;
		return;
	}
	int m = (l+r)>>1;
	while(l<m && tzy[v[m]].val == tzy[v[m-1]].val) m--;
	now = v[m];
	if(l < m) lift(l,m-1,tzy[now].l);
	else tzy[now].l = 0;
	lift(m+1,r,tzy[now].r);
	tzy[now].size = tzy[tzy[now].l].size + tzy[tzy[now].r].size + 1;
	tzy[now].fact = tzy[tzy[now].l].fact + tzy[tzy[now].r].fact + 1;
}

void rebuild(int& now) {
	v.clear();
	ldr(now);
	if(v.empty()) {
		now = 0;
		return;
	}
	lift(0,v.size()-1,now);
}

void update(int now,int end) {
	if(!now) return;
	if(tzy[end].val < tzy[now].val) update(tzy[now].l,end);
	else update(tzy[now].r,end);
	tzy[now].size = tzy[tzy[now].l].size + tzy[tzy[now].r].size + 1;
}

void check(int& now,int end) {
	if(now==end) return;
	if(imbalance(now)) {
		rebuild(now);
		update(now,end);
		return;
	}
	if(tzy[end].val < tzy[now].val) check(tzy[now].l,end);
	else check(tzy[now].r,end);
}

//====ins====

void ins(int& now,int val) {
	if(!now) {
		newNode(now,val);
		check(root,now);
		return;
	}
	tzy[now].fact++;
	tzy[now].size++;
	if(val < tzy[now].val) ins(tzy[now].l,val);
	else ins(tzy[now].r,val);
}

//====del====
//delete operation change the fact node's value
void del(int now,int val) {
	if(tzy[now].exits && tzy[now].val == val) {
		tzy[now].exits = 0;
		tzy[now].fact--;
		check(root,now);
		return;
	}
	tzy[now].fact--;
	if(val < tzy[now].val) del(tzy[now].l,val);
	else del(tzy[now].r,val);
}

//=====get rank====
int getrank(int val) {
	int now = root,rank = 1;
	while(now) {
		if(val <= tzy[now].val) now = tzy[now].l;
		else {
			rank += tzy[now].exits+tzy[tzy[now].l].fact;
			now = tzy[now].r;
		}
	}
	return rank;
}
//=====get num====
int getnum(int rank) {
	int now = root;
	while(now) {
		if(tzy[now].exits && tzy[tzy[now].l].fact + tzy[now].exits == rank) break;
		else if(tzy[tzy[now].l].fact >= rank) now = tzy[now].l;
		else {
			rank -= tzy[tzy[now].l].fact + tzy[now].exits;
			now = tzy[now].r;
		}
	}
	return tzy[now].val;
}

int main() {
	cnt = 0;
	int n,opt,x;
	scanf("%d",&n);
	while(n--) {
		scanf("%d%d",&opt,&x);
		switch(opt) {
			case 1:
				ins(root,x);
				break;
			case 2:
				del(root,x);
				break;
			case 3:
				printf("%d\n",getrank(x));
				break;
			case 4:
				printf("%d\n",getnum(x));
				break;
			case 5:
				printf("%d\n",getnum(getrank(x)-1));
				break;
			case 6:
				printf("%d\n",getnum(getrank(x+1)));
				break;
		}
	}
	return 0;
}
