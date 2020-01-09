//TODO Pairing Heap
#include <bits/stdc++.h>
using namespace std;

typedef struct NODE* PNode;
struct NODE {
	int data;
	PNode son,bro;
	NODE() { son = bro = nullptr; }
	NODE(int _data):data(_data) { son = bro = nullptr; }
};

//Min Pairing Heap
class PAIRINGHEAP {
	private:
		PNode root;
		int n;
	public:
		PAIRINGHEAP() { n=0; }
		PNode insert(int _data) {
			n++;
			if(n==1) {
				root = new NODE(_data);
				return root;
			}
			PNode _add = new NODE(_data);
			if(root->data > _add->data) swap(root,_add);
			_add->bro = root->son;
			root->son = _add;
			return root;
			//return root = merge(root,_add);
		}
		PNode merge(PNode pa,PNode pb) {
			if(pa==nullptr) return pb;
			else if(pb==nullptr) return pa;
			if(pa->data > pb->data) swap(pa,pb);
			pb->bro = pa->son;
			pa->son = pb;
			return pb;
		}
		PNode mergeBro(PNode _now) {
			if(!_now || !_now->bro) return _now;
			PNode nxt = _now->bro,nnxt = nxt->bro;
			_now->bro = nxt->bro = nullptr;
			return merge(merge(_now,nxt),mergeBro(nnxt));
		}
		PNode getMin() { return n==0? nullptr : root; }
		PNode delMin() { 
			n--;
			return root = mergeBro(root->son);
		}
};

int main() {
	std::ios::sync_with_stdio(false);
	PAIRINGHEAP p;
	p.insert(13);
	p.insert(12);
	p.insert(7);
	p.insert(3);
	p.insert(10);
	PNode ans;
	do {
		ans = p.getMin();
		cout << ans->data << " ";
		ans = p.delMin();
	} while(ans);
	cout << endl;
	return 0;
}
