#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e3+100;
char str1[maxn],str2[maxn];
int dp[maxn][maxn];
int len1,len2;

void print(int x,int y) {
    if(!x || !y) return;
    if(dp[x][y-1] == dp[x][y]) {
        print(x,y-1);
    }
    else if(dp[x-1][y] != dp[x][y]) {
        print(x-1,y-1);
        printf("%c",str2[y-1]);
    }
    else print(x-1,y);
    return;
}

int main() {
    scanf("%s",str1);
    scanf(" %s",str2);
    len1 = strlen(str1);
    len2 = strlen(str2);
    for(int i=0; i<len1; i++) {
        for(int j=0; j<len2; j++) {
            if(str1[i] == str2[j]) dp[i+1][j+1] = dp[i][j] + 1;
            else {
                dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
            }
        }
    }
    print(len1,len2);
    return 0;
}