#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    freopen("in","w",stdout);
    cout << 1 << endl;
    cout << "1000 1000\n";
    for(int i=0; i<1e3; i++)
    {
        for(int j=0; j<1e3; j++)
        {
            if(i==123 && j==321) cout << "J";
            else if(j*i*321 % 3 == 1) cout << "F";
            else if(i*j*5 % 2 == 1) cout << '#';
            else if(i*j*4 % 2 == 0) cout << '.';
            else cout << ".";
        }
        cout << endl;
    }
    return 0;
}
