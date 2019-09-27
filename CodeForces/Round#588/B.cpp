#include <iostream>
#include <string>
using namespace std;

int main() {
    int n,k;
    string str;
    cin >> n >> k >> str;
    k = min(n,k);
    if(n==k && k==1) putchar('0');
    else {
        int i;
        for(i=0; i<n&&k; i++) {
            if(i==0) {
                putchar('1');
                if(str[i] != '1') k--;
            } else {
                putchar('0');
                if(str[i] != '0') k--;
            }
        }
        while(i<n) {
            putchar(str[i]);
            i++;
        }
    }
}
