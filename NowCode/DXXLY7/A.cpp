//After Contest 2019-8-9
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;


bool isExpMini(const string &a) {
    int i=0,j=1,k=0;
    int n = a.size();
    while(k<n && i<n && j<n) {
        if(a[(i+k)%n] == a[(j+k)%n]) k++;
        else {
            a[(i+k)%n] > a[(j+k)%n]? i = i+k+1 : j = j+k+1;
            if(i==j) i++;
            k = 0;
        }
    }
    return (min(i,j) == 0);
}

int main() {
    int n;
    string in,tmp;
    cin >> n;
    while(n--) {
        cin >> in;
        int i = 0;
        queue<string> L;
        while(i<in.size()) {
            for(int j=in.size()-1; j>=i; j--) {
                tmp = "";
                for(int k=i; k<=j; k++){
                    tmp+=in[k];
                }
                if(isExpMini(tmp)) {
                    //cout << tmp << endl;
                    L.push(tmp);
                    i = j;
                    break;
                }
            }
            i++;
        }
        while(!L.empty()) {
            cout << L.front();
            L.pop();
            if(!L.empty()) cout << " ";
        }
        cout << endl;
    }
    return 0;
}


