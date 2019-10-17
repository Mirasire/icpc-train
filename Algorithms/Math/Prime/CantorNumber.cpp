#include <iostream>
#include <string>
using namespace std;

int factor[20];

int main(){
    //factorInit
    factor[0] = 1;
    for(int i=1; i<20; i++) factor[i] = factor[i-1]*i;

    int N;
    string List;
    cin >> N;
    cin >> List;
    int CantorNumber = 0;
    for(int i=0,index=N-1; i<N; index--,i++){
        int cnt = 0;
        for(int j=i+1; j<N; j++)
            if(List[j] < List[i]) cnt++;
        CantorNumber += cnt*factor[index];
    }
    cout << "This List's CantorNumber = " << CantorNumber << endl;
    return 0;
}


    