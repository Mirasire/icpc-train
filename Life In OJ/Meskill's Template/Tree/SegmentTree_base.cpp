//区间更新-维护平方和，立方和，和
//1-^1 2-^2 3-^3
typedef long long int ll;
const ll maxn = 1e5+10,MOD = 1e4+7;
ll out;

//evey Node = ax+b
struct ND{
    ll l,r;
    ll sum[5],a,b;
    void mult(ll m) {
        a = a*m%MOD;
        b = b*m%MOD;
        sum[1] = m*sum[1]%MOD;
        sum[2] = m*m%MOD*sum[2]%MOD;
        sum[3] = m*m%MOD*m%MOD*sum[3]%MOD;
    }
    void add(ll ad) {
        b = (b+ad)%MOD;
        sum[3] = (((sum[3] + 3*ad%MOD*sum[2]%MOD)%MOD + 3*ad%MOD*ad%MOD*sum[1]%MOD)%MOD+ad%MOD*ad%MOD*ad%MOD*(r-l+1)%MOD)%MOD;
        sum[2] = ((sum[2] + sum[1]*2%MOD*ad%MOD)%MOD + ad%MOD*ad%MOD*(r-l+1)%MOD)%MOD;
        sum[1] = (sum[1] + (r-l+1)*ad%MOD)%MOD;
    }
    void def(ll m,ll ad) {
        mult(m);
        add(ad);
    }
};
ND sgt[maxn<<2];

void build(int i,ll l,ll r) {
    sgt[i].l = l;
    sgt[i].r = r;
    sgt[i].sum[1] = sgt[i].sum[2] = sgt[i].sum[3] = sgt[i].b = 0;
    sgt[i].a = 1;
    if(l==r) return;
    ll mid = (l+r) >> 1;
    build(i<<1,l,mid);
    build(i<<1|1,mid+1,r);
}

void up(int index) {
    for(int i=1; i<=3; i++) 
        sgt[index].sum[i] = (sgt[index<<1].sum[i] + sgt[index<<1|1].sum[i])%MOD;
}

void down(int i) {
    if(sgt[i].a!=1 || sgt[i].b!=0) {
        sgt[i<<1].def(sgt[i].a,sgt[i].b);
        sgt[i<<1|1].def(sgt[i].a,sgt[i].b);
        sgt[i].a = 1,sgt[i].b = 0;
    }
}

void modify(int i,ll de,ll type,ll L,ll R) {
    if(sgt[i].l >= L && sgt[i].r <= R) {
        if(type==1) sgt[i].def(1,de);
        else if(type==2) sgt[i].def(de,0);
        else sgt[i].def(0,de);
        return;
    }
    ll mid = (sgt[i].l+sgt[i].r) >> 1;
    down(i);
    if(mid >= L) modify(i<<1,de,type,L,R);
    if(mid < R) modify(i<<1|1,de,type,L,R);
    up(i);
}
void query(int i,ll L,ll R,ll idx) {
    if(sgt[i].l >= L && sgt[i].r <= R) {
        out = (out + sgt[i].sum[idx]) % MOD;
        return;
    } 
    ll mid = (sgt[i].l+sgt[i].r) >> 1;
    down(i);
    if(mid >= L) query(i<<1,L,R,idx);
    if(mid < R) query(i<<1|1,L,R,idx);
}
