#include <algorithm>
#include <cstdio>
#include <iostream>
#include <limits.h>
#include <cmath>
using namespace std;

const int maxn = 3e5+100;
int arr[maxn];

int main(){
    int n,Min = INT_MAX,index=INT_MAX;
    int Guess = INT_MAX;
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%d",arr+i);
        if(arr[i] <= Min){
            if(arr[i] < Min) index=i;
            else if((n-i) < (index-1)) index = i;
            Min = arr[i];
        }
        int tmp = arr[i]/max(n-i,i-1);
        Guess = min(Guess,tmp);
    }
    int lon = max(n-index,index-1);
    cout << min(Guess,Min/lon) << endl;
    return 0;
}
