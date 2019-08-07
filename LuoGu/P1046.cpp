#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int arr[10];
    int sc;
    for(int i=0; i<10; i++){
        scanf("%d",arr+i);
    }
    scanf("%d",&sc);
    sc+=30;
    int cnt = 0;
    for(int i=0; i<10; i++){
        if(arr[i] <= sc) cnt++;
    }
    cout << cnt;
    return 0;
}
        
