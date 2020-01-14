//TODO
#include <bits/stdc++.h>
using namespace std;

typedef struct NODE* PNode;
struct NODE {
	int val;
	PNode ch,br;
	NODE() {}
	NODE(int _val):val(_val),ch(nullptr),br(nullptr) {}
	void display() { cout << val << " "; }
};

class PAIRINGHEAP {
	public:
		PNode root;
		int n;
		PAIRINGHEAP() { root = new NODE(); n = 0; }
		PAIRINGHEAP(int arr[],int _size) {
		}
		void insert(int val) {
			if(!n) {root = new NODE(val);}
			else {
				PNode _add = new NODE(val);
				root = merge(root,_add);
			}
			n++;
		}
		PNode merge(PNode a,PNode b) {
			if(a == nullptr) return b;
			else if(b == nullptr) return a;
			if(a->val > b->val) swap(a,b);
			b->br = a->ch;
			a->ch = b;
			return a;
		}
		PNode mergeBro(PNode x) {
			if(x==nullptr || x->br == nullptr) return x;
			PNode n1,n2;
			n1 = x->br; n2 = n1->br;
			n1->br = x->br = nullptr;
			return merge(merge(x,n1),mergeBro(n2));
		}
		void delMin() {
			n--;
			PNode tmp = root;
			root = mergeBro(root->ch);
			delete(tmp);
		}
		int getMin() { return root->val; }
		void display() {
			queue<PNode> list;
			list.push(root);
			while(!list.empty()) {
				PNode tmp = list.front();
				list.pop();
				while(tmp != nullptr) {
					tmp->display();
					if(tmp->ch != nullptr) list.push(tmp->ch);
					tmp=tmp->br;
				}
			}
			cout << endl;
		}
};

int main() {
	//for test
	std::ios::sync_with_stdio(false);
	PAIRINGHEAP pair;
	pair.insert(13);
	cout << pair.root->val << endl;
	pair.insert(24);
	cout << pair.root->val << endl;
	pair.insert(6);
	cout << pair.root->val << endl;
	pair.insert(1);
	cout << pair.root->val << endl;
	pair.insert(12);
	cout << pair.root->val << endl;
	pair.display();
	pair.delMin();
	pair.display();
	return 0;
}
