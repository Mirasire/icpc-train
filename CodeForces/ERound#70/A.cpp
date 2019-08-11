#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main() {
    int n,id1,id2;
    int i,j;
    scanf("%d",&n);
    string a,b;
    while(n--) {
        cin >> a >> b;
        id1 = id2 = 0;
        for(i = b.size()-1,j=0; i>=0; i--,j++) {
            if(b[i]=='1') {
                id1 = j;
                break;
            }
        }
        for(i = a.size()-1,j=0; i>=0; j++,i--) {
            if(a[i] == '1' && j>= id1) {
                id2 = j;
                break;
            }
        }
        if(id2 == 0) cout << 0 << endl;
        else cout << id2 - id1 << endl;
    }
    return 0;
}
