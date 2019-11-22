//如果这个WA了，就修改Build函数
//out.size() 调用 <vector>
typedef long long int ll;
const ll maxn = 2e4+100;
set<int> out;
ll a[maxn*2],L[maxn],R[maxn];
ll l[maxn],r[maxn];
struct NO {
    int l,r;
    int color;
};
NO sgt[maxn << 2];

// 0 - wu -1 = za else = color
void build(int i,int l,int r) {
    sgt[i].l = l;
    sgt[i].r = r;
    sgt[i].color = 0;
    if(l==r) return;
    int mid = (l+r)>>1;
    build(i<<1,l,mid);
    build(i<<1|1,mid+1,r);
}
void up(int i) {
    if(sgt[i<<1].color ^ sgt[i<<1|1].color) sgt[i].color = -1;
    else sgt[i].color = sgt[i<<1].color;
}

void down(int i) {
    if(sgt[i].color == -1) return;
    sgt[i<<1].color = sgt[i<<1|1].color = sgt[i].color;
}

void modify(int i,int tl,int tr,int def) {
    if(sgt[i].l >= tl && sgt[i].r <= tr) {
        sgt[i].color = def;
        return;
    }
    //if(sgt[i].l == sgt[i].r) return;
    int mid = (sgt[i].l+sgt[i].r) >> 1;
    down(i);
    if(mid >= tl) modify(i<<1,tl,tr,def);
    if(mid < tr) modify(i<<1|1,tl,tr,def);
    up(i);
}

void query(int i) {
    if(sgt[i].color != -1 && sgt[i].color != 0) {
        out.insert(sgt[i].color);
        return;
    }
    if(sgt[i].l == sgt[i].r) return;
    down(i);
    query(i<<1);
    query(i<<1|1);
}
