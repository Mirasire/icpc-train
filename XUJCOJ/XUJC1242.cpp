#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

const int maxn = 120;
int a[maxn][maxn],b[maxn][maxn],c[maxn][maxn];

int main(){
    int r1,r2,c1,c2;
    cin >> r1 >> c1;
    for(int i=0; i<r1; i++)
        for(int j=0; j<c1; j++) 
            cin >> a[i][j];
    cin >> r2 >> c2;
    if(c1 != r2) {
        cout << "-1\n";
        return 0;
    }
    for(int i=0; i<r2; i++)
        for(int j=0; j<c2; j++) 
            cin >> b[i][j];
    for(int i=0; i<r1; i++){
        for(int j = 0; j<c2; j++){
            int sum = 0;
            for(int k=0; k<r2; k++) sum += a[i][k]*b[k][j];
            c[i][j] = sum;
        }
    }
    printf("%d %d\n",r1,c2);
    for(int i=0; i<r1; i++)
        for(int j=0; j<c2; j++)
            printf("%d%c",c[i][j]," \n"[j==c2-1]);
    return 0;
}
