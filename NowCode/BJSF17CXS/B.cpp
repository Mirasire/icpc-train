#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

long long fac[15][20] = {0};

void Init(){
    for(long long i=1; i<=10; i++) fac[i][0] = 1;
    for(long long i=1; i<=10; i++){
        for(long long j=1; j<19; j++){
            fac[i][j] = fac[i][j-1]*i;
        }
    }
    return;
}

int main(){
    Init();
    long long n;
    string l;
    scanf("%lld",&n);
    while(n--){
        cin >> l;
        long long lon = l.size(); 
        long long sum=0;
        for(long long i=0,index=lon-1; i<lon; i++,index--){
            sum += (fac[2][i] + fac[3][i] + fac[4][i] + fac[5][i] + fac[6][i] + fac[7][i] + fac[8][i] + fac[9][i] + fac[10][i]) * ( l[index] - '0');
        }
        printf("%lld\n",sum);
    }
    return 0;
}
            
            
