//AC
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 1e3+100;
struct COW {
    int x,y,r;
} cow[maxn];

/*
x1,y1 r1
x2,y2 r2
abs(x1-x2)^2+abs(y1-y2)^2 < (r1+r2)^2
*/
bool isFire(COW& c1,COW& c2) {
    int x=abs(c1.x-c2.x),y=abs(c1.y-c2.y),r=c1.r+c2.r;
    return x*x+y*y < r*r;
}

int main() {
    int n,num;
    int x,y,r;
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        scanf("%d%d%d",&cow[i].x,&cow[i].y,&cow[i].r);
    }
    for(int i=0; i<n; i++) {
        num=0;
        for(int j=0; j<n; j++) {
            if(i==j) continue;
            num += isFire(cow[i],cow[j]);
        }
        printf("%d\n",num);
    }
    return 0;
}