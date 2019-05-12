#include <cstdio>
#include <queue>
using namespace std;

struct Node{
    int a[10];
    int size;
    int hash;
};

int fac[10] = 0;

void FacInit(){
    fac[0] = 1;
    for(int i=1; i<10; i++) fac[i] = fac[i-1] * i;
    return;
}

void get_hash(int *arr,int size){
    int hash = 0;
    for(int i=0,index=size-1; i<size; i++,index--){
        int cnt = 0;
        for(int j=i+1; j<size; j++){
            if(arr[j] < arr[i]) cnt++;
        }
        hash += cnt*fac[index];
    }
    return hash;
}


int main(){
    int n;
    while(scanf("%d",&n) != EOF){
        if(n==0) break;
        Node Tmp;
        Tmp.size = n;
        for(int i=0; i<n; i++) scanf("%d",Tmp.a+i);
        T.hash = get_hash(Tmp.a,Tmp.size);
        bfs();
    }
    return 0;
}

