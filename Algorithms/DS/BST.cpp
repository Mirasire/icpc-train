#include <iostream>
#include <queue>
using namespace std;

const int INF = 0x3f3f3f;

typedef struct NODE* PNode;
struct NODE {
    int val;
    PNode lc,rc;
    NODE(int& val):val(val),lc(NULL),rc(NULL) {}
    NODE():val(INF),lc(NULL),rc(NULL) {}
};

class bsTree {
    private:
    PNode insert(int data,PNode _rt) {
        if(_rt == NULL || _rt->val == INF) {
            _rt = new NODE(data);
            return _rt;
        }
        else if(data < _rt->val) _rt->lc = insert(data,_rt->lc);
        else _rt->rc = insert(data,_rt->rc);
    }
    PNode earse(int data,PNode _rt) {
        if(data == _rt->val) {
            if(_rt->lc==NULL && _rt->rc==NULL) {
                delete _rt;
                return NULL;
            }
            else if(_rt->lc==NULL || _rt->rc==NULL) {
                PNode tmp = _rt->lc==NULL? _rt->rc : _rt->lc;
                delete _rt;
                return tmp;
            } else {
                PNode tmp = findRightMin(_rt->rc);
                cout << tmp->val << endl;
                _rt->val = tmp->val;
                _rt->rc = earse(tmp->val,_rt->rc);
                return _rt;
            }
        }
        else if(data < _rt->val) {
            _rt->lc = earse(data,_rt->lc);
        }
        else {
            _rt->rc = earse(data,_rt->rc);
        }
    }
    void acend(PNode _now) {
        if(_now == NULL) {
            cout << "Tree is Empty now";
            return;
        }
        if(_now->lc) acend(_now->lc);
        cout << _now->val << " ";
        if(_now->rc) acend(_now->rc);
    }
    public:
    PNode _root;
    bsTree() { _root = new NODE(); }
    bsTree(int arr[],int n) {
        _root=new NODE();
        for(int i=0; i<n; i++) insert(arr[i]);
    }
    PNode findLeftMax(PNode _rt) {
        if(_rt->rc==NULL) return _rt;
        return findLeftMax(_rt->rc);
    }
    PNode findRightMin(PNode _rt) {
        if(_rt->lc==NULL) return _rt;
        return findRightMin(_rt->lc);
    }
    PNode find(int data) {
        PNode tmp = _root;
        while(tmp) {
            if(data > tmp->val) tmp = tmp->rc;
            else if(data < tmp->val) tmp = tmp->lc;
            else return tmp;
        }
        return NULL;
    }
    void insert(int data) { _root = insert(data,_root); }
    void earse(int data) { _root = earse(data,_root); }
    void acend() { acend(_root); }
    void display() {
        queue<PNode> list;
        list.push(_root);
        while(!list.empty()) {
            PNode now = list.front();
            cout << now->val << ": ";
            list.pop();
            if(now) {
                if(now->lc) {
                    cout << "L: " << now->lc->val << " ";
                    list.push(now->lc);
                }
                if(now->rc) {
                    cout << "R: " << now->rc->val << " ";
                    list.push(now->rc);
                }
            }
            cout << endl;
        }
    }
};

//for test
int main() {
    int arr[7] = {63,55,90,42,70,98,67};
    bsTree bst(arr,7);
    //bst.insert(1);
    cout << "------------" << endl;
    bst.acend();
    cout << endl;
    bst.display();
    //delete
    bst.earse(63);
    cout << "------------" << endl;
    bst.acend();
    cout << endl;
    bst.display();
    return 0;
}