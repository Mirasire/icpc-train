//Ac tag: implementation
#include <iostream>
using namespace std;

const int maxn = 45;
int ans[maxn][maxn];

int main() {
    int n,endY;
    scanf("%d",&n);
    endY = n;
    //1-n
    ans[1][n/2+1] = 1;
    int perX = 1,perY = n/2+1;
    n*=n;
    for(int i=2; i<=n; i++) {
        if(perX==1 && perY!=endY) {
            perX = endY; perY++;
            ans[perX][perY] = i;
        }
        else if(perY==endY && perX!=1) {
            perX--; perY=1;
            ans[perX][perY] = i;
        }
        else if(perX==1 && perY==endY) {
            perX++;
            ans[perX][perY] = i;
        } 
        else {
            if(!ans[perX-1][perY+1]) {
                perX--; perY++;
                ans[perX][perY] = i;
            } else {
                perX++;
                ans[perX][perY] = i;
            }
        }
    }
    for(int i=1; i<=endY; i++)
        for(int j=1; j<=endY; j++)
            printf("%d%c",ans[i][j]," \n"[j==endY]);
    return 0;
}