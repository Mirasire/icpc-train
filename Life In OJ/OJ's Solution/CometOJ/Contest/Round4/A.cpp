#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int T;
    int p[7];
    cin >> T;
    while(T--){
        memset(p,0,sizeof(p));
        int index;
        for(int i=0; i<5; i++){
            cin >> index;
            p[index]++;
        }
        int i=1;
        for(int j=2; j<=5; j++){
            if(p[i] < p[j]) i = j;
        }
        cout << i << endl;
    }
    return 0;
}
