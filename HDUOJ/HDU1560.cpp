#include <cstdio>
#include <cstring>

const int maxn = 100;
char Str[maxn][maxn];
char tmp[100];

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=0; i<n; i++){
            scanf(" %[^\n]",Str[i]);
        }
