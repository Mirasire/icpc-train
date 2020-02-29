#include <iostream>
#include <stack>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 3e2;
int per[maxn],in[maxn],n,visite[maxn],cnt;

struct TreeNode {
    int  data,index;
    TreeNode *lchild,*rchild;
    TreeNode(void) :lchild(nullptr),rchild(nullptr) {};
};
typedef TreeNode * PtreeNode;
stack<PtreeNode> List;

int find_index(int t) {
    for(int i=0; i<n; i++) {
        if(in[i] == t) return i;
    }
}

bool full(int index) {
    bool lf,rf;
    lf = rf = 0;
    if(index == 0  || visite[index - 1]) lf = 1;
    if(index == n-1  || visite[index + 1]) rf = 1;
    return (lf&&rf);
}

void insert(PtreeNode now,int t) {
    int t_index = find_index(t);
    visite[t_index]  = 1;
    PtreeNode next  = new TreeNode;
    next->index = t_index;
    next->data = t;
    if(t_index < now->index) now->lchild  = next; 
    else now->rchild = next;
    List.push(next);
}

void post_travel(PtreeNode now) {
    if(now == nullptr) return;
    post_travel(now->lchild);
    post_travel(now->rchild);
    cnt++;
    printf("%d%c",now->data," \n"[n==cnt]);
}



int main() {
    freopen("in","r",stdin);
    cnt = 0;
    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%d",per+i);
    for(int i=0; i<n; i++) scanf("%d",in+i);
    PtreeNode root,now;
    root  = new TreeNode;
    root->data = per[0];
    root->index = find_index(root->data);
    visite[root->index] = 1;
    now = root;
    List.push(now);
    for(int i=1; i<n; i++) {
        now = List.top();
        while(full(now->index)) {
                now = List.top();
                List.pop();
        }
        //cout << "i " << i << " now->data " << now->data << endl;
        insert(now,per[i]);
    }
    post_travel(root);
    return 0;
}
