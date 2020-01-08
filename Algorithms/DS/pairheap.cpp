#include <cstdio>
#include <cstring>

typedef struct NODE* PNode;
struct NODE {
    int val;
    PNode fa,son,bro;
    NODE(): { fa = son = bro = nullptr; }
    NODE(int _val,PNode _fa,PNode _son,PNode _bro) : val(_val),fa(_fa),son(_son),bro(_bro) {}
};

class pairingHeap {
    private:
    PNode root;
    pairingHeap() { root = new NODE(); }
    public:
};

int main() {
    return 0;
}