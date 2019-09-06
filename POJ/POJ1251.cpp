#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int Emaxn = 120,Hmaxn = 30;
struct EDGE {
    int to,next,w;
};

struct INSERT {
    int to,w;
    INSERT(){}
    INSERT(int a,int b):to(a),w(b) {}
};
bool const operator < (const INSERT &a,const INSERT &b) {
    return a.w > b.w;
}

EDGE edge[Emaxn<<1];
bool vis[Hmaxn];
int head[Hmaxn],cnt;
priority_queue<INSERT> List;

void addEdge(int a,int b,int ww) {
    cnt++;
    edge[cnt].to = b;
    edge[cnt].w = ww;
    edge[cnt].next = head[a];
    head[a] = cnt;
}

int Prim(void) {
    //Init
    int out = 0,i;
    while(!List.empty()) List.pop();
    INSERT now(1,0);
    List.push(now);
    //List.clear();
    while(!List.empty()) {
        now = List.top();
        List.pop();
        if(vis[now.to]) continue;
        out += now.w; //MST habbened
        vis[now.to] = 1;
        for(i = head[now.to]; i != -1; i=edge[i].next) {
            if(vis[edge[i].to]) continue;
            List.push(INSERT(edge[i].to,edge[i].w));
        }
    }
    return out;
}

int main() {
    int n,tp;
    char node;
    int a,b,ww;
    while(scanf("%d",&n) != EOF) {
        if(!n) break;
        memset(head,-1,sizeof(int)*(n+1));
        memset(vis,0,sizeof(bool)*(n+1));
        cnt = 0;
        for(int i=1; i<n; i++) {
            scanf(" %c %d",&node,&tp);
            a = (int)node - (int)'A' + 1;
            //cout << a << " " << tp << endl;
            while(tp--) {
                scanf(" %c %d",&node,&ww);
                b = (int)node - (int)'A' + 1;
                //cout << b << " " << ww << endl;
                addEdge(a,b,ww);
                addEdge(b,a,ww);
            }
        }
        printf("%d\n",Prim());
    }
}
