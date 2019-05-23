#include <iostream>
#include <string>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string n;
        int lon;
        cin >> lon >> n;
        int index = -1;
        for(int i=0; i<lon; i++){
            if(n[i] == '8'){
                index = i;
                break;
            }
        }
        if(index != -1){
            if(lon - index >= 11) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
