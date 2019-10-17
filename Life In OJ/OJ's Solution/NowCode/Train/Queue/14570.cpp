/*
 * https://ac.nowcoder.com/acm/problem/14570
 */

#include <stdio.h>
#include <queue>
using namespace std;

struct STATUS{
    int m;
    int t;
    STATUS():m(0),t(0) {}
    STATUS(int m,int t):m(m),t(t) {}
    void display(){
        printf("fdb m: %d t: %d\n",m,t);
    }
};

const int maxn = 2e3+100;
int Pi[maxn],Ci[maxn];
int n,l,mx,s;

bool find(){
    queue<STATUS> list;
    STATUS now(s,mx),next;
    list.push(now);
    int in = 1;
    for(int i=0; i<n; i++){
        int end = in;
        in = 0;
        if(list.empty()) break;
        for(int j=0; j<end; j++){
            if(!list.empty()) now = list.front();
            else break;
            list.pop();
            if(now.t >= Pi[i]){
                if(now.m >= Ci[i]){
                    in++; 
                    next.m = now.m - Ci[i];
                    next.t = mx;
                    //next.display();
                    list.push(next);
                }
                in++;
                next.m = now.m;
                next.t = now.t - Pi[i];
                //next.display();
                list.push(next);
            }
        }
    }
    /*Debug
    while(!list.empty()){
        now = list.front();
        list.pop();
        now.display();
    }
    */
    if(list.empty()) return 0;
    return 1;
}

int main(){
    while(scanf("%d%d%d%d",&n,&l,&mx,&s) != EOF){
        int f;
        int N = n;
        for(int i=0; i<n; i++) {
            int d;
            scanf("%d%d",&d,Ci + i);
            if(i > 0) {
                Pi[i] = d - f;
                if(Pi[i] == 0){
                    if(Ci[i-1] >= Ci[i])  Ci[i-1] = Ci[1];
                    N--;
                    i--;
                }
            }
            else Pi[i] = d;
            f = d;
        }
        n = N;
        Pi[n] = l - f;
        Ci[n] = 0;
        n++;
        if(find()) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
