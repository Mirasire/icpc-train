// 0 0 should input ac
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

const int maxn = 1e5+100;
int f[maxn];

int fi(int id){
    int t1,t2 = id;
    while(id != f[id]) id = f[id];
    while(id != t2){
        t1 = f[t2];
        f[t2] = id;
        t2 = t1;
    }
    return id;
}

int main(){
    int a,b;
    int kase = 0;
    while(1){
        bool flag = 1;
        for(int i=0; i<maxn; i++) f[i] = i;
        stack<int> input;
        set<int> apper;
        while(scanf("%d%d",&a,&b)){
            if(a == -1 && b == -1) return 0; 
            if(a == 0 && b == 0) break;
            if(!apper.count(a)) {
                apper.insert(a);
                input.push(a);
            }
            if(!apper.count(b)) {
                apper.insert(b);
                input.push(b);
            }
            if(flag) {
                int r_a = fi(a);
                int r_b = fi(b);
                if(r_a == r_b) flag = 0;
                else f[r_a] = r_b;
            }
        }
        if(flag) {
            int total = 0,fl=1;
            while(!input.empty()){
                int id = input.top();
                input.pop();
                if(id == f[id]) total++;
                if(total > 1) {
                    fl = 0;
                    break;
                }
            }
            if(fl) printf("Case %d is a tree.\n",++kase);
            else printf("Case %d is not a tree.\n",++kase);
        }
        else printf("Case %d is not a tree.\n",++kase);
    }
    return 0;
}

