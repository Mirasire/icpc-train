#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 2e6+100;
int a[maxn]={0};
int b[maxn]={0};

int main(){
    int N,A,M;
    scanf("%d%d%d",&N,&A,&M);
    a[1] = A;
    for(int i=2; i<=N; i++){
        a[i] = (a[i-1] + (7*i))%M;
    }
    for(int j=1; j<=N; j++){
        int st = j;
        while(st <= N){
            b[j] += a[st];
            st+=j;
        }
        if(j>1) b[1] ^= b[j];
    }
    printf("%d",b[1]);
    return 0;
}

        

