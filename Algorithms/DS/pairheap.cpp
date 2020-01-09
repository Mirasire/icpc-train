#include <cstdio>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

typedef struct NODE* PNode;
struct NODE {
    int val;
    PNode fa,son,bro;
    NODE(): { val = INF; fa = son = bro = nullptr; }
    NODE(int _val,PNode _fa,PNode _son,PNode _bro) : val(_val),fa(_fa),son(_son),bro(_bro) {}
};

class PAIRINGHEAP{
    private:
    PNode root;
    int n;
    public:
    PAIRINGHEAP() { root = new NODE(); n = 0; }
    PAIRINGHEAP(int arr[],int _size) { 
        root = new NODE();  n = 0;
        for(int i=0; i<_size; i++) insert(arr[i]);
    }
    //insert _rt && data
    PNode insert(PNode _rt,int val) {
        n++;
        if(n==0) {
            _rt = new NODE(val,nullptr,nullptr,nullptr);
            return _rt;
        }
        PNode add = new NODE();
        add->val = val;
        if(_rt->val > val) swap(add,_rt);
        add->bro = _rt->son;
        add->fa = _rt;
        _rt->son = add;
        return _rt;
    }
    //merge
    PNode merge(PNode pa,PNode pb) {
        if(pa == nullptr) return pb;
        else if(pb == nullptr) return pa;
        if(pa->val > pb->val) swap(pa,pb);
        //init
        pa->fa = pb->fa = nullptr;
        //link
        pb->fa = pa;
        pb->bro = pa->son;
        pa->son = pb;
        return pa;
    }
    PNode mergeBro(PNode now) {
        if(now == nullptr || now->bro == nullptr) return now;
        PNode nxt = now->bro,nnxt = nxt->bro;
        now->fa = nxt->fa = nullptr;
        //cut link
        nxt->bro = now->bro = nullptr;
        return merge(merge(now,nxt),mergeBro(nnxt));
    }
    void deleteMin() {
        PNode tmp = root;
        root = mergeBro(_root->bro);
        if(tmp) delete(tmp);
    }
    PNode getMin(){ return n==0? nullptr : root; }
    //decrease-key
};

int main() {
    return 0;
}