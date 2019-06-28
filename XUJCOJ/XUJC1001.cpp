#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
using namespace std;


typedef struct BinNode*  PBinNode;
struct BinNode{
    PBinNode lc,rc,parent;
    int data;
    BinNode(): lc(nullptr),rc(nullptr),parent(nullptr),data(0) {}
};

int main(){
    int N;
    scanf("%d",&N);
    vector<int> arr;
    stack<PBinNode *> List;
    int in;
    for(int i=0; i<N; i++){
        scanf("%d",&in);
        arr.push_back(in);
    }

    if(N==1){
        printf("%d",arr[0]);
        return 0;
    }

    int a,b;
    sort(arr.begin(),arr.end());
    scanf("%d%d",&a,&b);
    PBinNode root = new BinNode();
    root->data = arr[a];
    arr.erase(arr.begin() + a);
    List.push(&root->rc);
    List.push(&root->lc);

    for(int i=0; i<N-1; i++){
        sort(arr.begin(),arr.end());
        scanf("%d%d",&a,&b);
        PBinNode add = new BinNode();
        PBinNode* father = List.top();
        List.pop();
        *father = add;
        if(a!=-1) add->data = arr[a];
        else add->data = arr[0];
        if(a!= -1) arr.erase(arr.begin() + a);
        else arr.erase(arr.begin());
        if(b>0) List.push(&add->rc);
        if(a>0) List.push(&add->lc);
    }
    queue<PBinNode> out;
    PBinNode now;
    bool flag = 0;
    out.push(root);
    while(!out.empty()){
        if(flag) printf(" ");
        else flag = 1;
        now = out.front();
        out.pop();
        printf("%d",now->data);
        if(now->lc != nullptr)
        out.push(now->lc);
        if(now->rc != nullptr)
        out.push(now->rc);
    }

    return 0;
}
