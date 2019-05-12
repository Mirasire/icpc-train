#include <iostream>
#include <map>
#include <string>
#include <cstdio>
using namespace std;

int main(){
    int n,out=0;
    string op;
    scanf("%d",&n);
    cin >> op;
    for(int i=0; i<n; i++){
        if(op[i] == '+') out++;
        else{
            if(out==0) continue;
            else out--;
        }
    }
    printf("%d",out);
    return 0;
}
    

