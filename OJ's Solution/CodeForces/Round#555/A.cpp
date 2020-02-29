#include <cstdio>
#include <map>
using namespace std;

int main(){
    int n,cnt=0;
    scanf("%d",&n);
    map<int,bool> visite;
    while(1){
        if(!visite[n]){
            cnt++;
            visite[n] = 1;
            n++;
        }else break;
        while(n%10==0){
            n/=10;
        }
    }
    printf("%d\n",cnt);
    return 0;
}

    
