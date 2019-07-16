#include <iostream>
#include <cstdio>
#include <algorithm>
#include <limits.h>
#include <vector>
using namespace std;

const int maxn = 120;
struct R{
    int data[4];
    R(){}
    R(int a,int b,int c,int d) {
        data[0] = a;
        data[1] = b;
        data[2] = c;
        data[3] = d;
    }
};

bool cmp(const R& a, const R& b){
    if(a.data[0] == b.data[0]) return a.data[2] < b.data[2];
    return a.data[0] < b.data[0];
}

int main(){
    freopen("farmer.in","r",stdin);
    freopen("farmer.out","w",stdout);
    int a,b,n,x,y,r,area,sum_w,now_w;
    int w1,w2,h1,h2;
    vector<R> roun;
    R tmp;
    scanf("%d%d%d",&a,&b,&n);
    area = a*b;
    for(int i=0; i<n; i++) {
        scanf("%d%d%d",&x,&y,&r);
        tmp.data[0] = max(0,x-r);
        tmp.data[1] = min(a,x+r);
        tmp.data[2] = max(0,y-r);
        tmp.data[3] = min(b,y+r);
        roun.push_back(tmp);
    }
    bool flag = 1;
    int now = 0;
    while(flag || now<roun.size()){
        //cout << "now " << now << endl;
        //cout << roun.size() << endl;
        flag = 0;
        for(int i=0; i<roun.size(); i++) {
            if(i==now) continue;
            w1 = max(roun[now].data[1],roun[i].data[1]) - min(roun[now].data[0],roun[i].data[0]);
            w2 = roun[now].data[1]+roun[i].data[1] - roun[now].data[0]-roun[i].data[0];
            h1 = max(roun[now].data[3],roun[i].data[3]) - min(roun[now].data[2],roun[i].data[2]);
            h2 = roun[now].data[3]+roun[i].data[3] - roun[now].data[2]-roun[i].data[2];
            //cout << " w1 w2 " << w1 << " " << w2 << endl;
            //cout << " h1 h2 " << h1 << " " << h2 << endl;
            if(w1 <= w2 && h1 <= h2) {
                flag = 1;
                roun[now].data[0] = min(roun[now].data[0],roun[i].data[0]);
                roun[now].data[1] = max(roun[now].data[1],roun[i].data[1]);
                roun[now].data[2] = min(roun[now].data[2],roun[i].data[2]);
                roun[now].data[3] = max(roun[now].data[3],roun[i].data[3]);
                roun.erase(roun.begin()+i);
                i--;
            }
        }
        if(flag) now = 0;
        else now++;
    }
    for(int i=0; i<roun.size(); i++){
        area -= (roun[i].data[3] - roun[i].data[2])*(roun[i].data[1] - roun[i].data[0]);
    }
    printf("%d\n",area);
    return 0;
}
        
        

